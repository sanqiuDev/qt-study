//#pragma execution_character_set("utf-8")

#include "test02.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    test02 window;
   
    //调整：尺寸和窗口标题、名字
    window.resize(1000, 700);
    window.setWindowTitle(QStringLiteral("控件窗口")); //字面量直接转为 Unicode 字符串，绕开系统编码问题


    //window.setObjectName("我的名字叫test02 window");
    /* 注意细节：
    流程拆解（问题根源）程序执行顺序：
        main() → test02 window;  // 第一步：调用test02的构造函数
        → 构造函数内部创建label、textEdit，执行setText拼接parent()->objectName()
        → 回到main函数，才执行 window.setObjectName("我的名字叫test02 window");
        执行构造函数的时候，窗口还没设置 objectName，此时 objectName() 返回默认值 test02Class（UI 自动生成的默认名称）
        等你在 main 里设置名字时，文本框文字早就已经计算完成渲染好了，后面修改 objectName 不会自动刷新文本框内容
    */
    //QLabel label;
    //label.setText(window.children()->objectName());
    /*
       1. QLabel label; 栈对象无父，且不能这么写
        QWidget 控件不能直接在 main 函数栈上创建，栈对象生命周期结束会自动析构，且没有父对象管理；
        正确动态创建写法（堆分配，交给 window 管理）

        window.children() 的返回值是 QList<QObject*>（对象指针列表），
        不是单个对象指针，列表不能用 -> 访问成员函数，编译器直接报错红波浪
    */
    
    window.show();
    return app.exec();
}
