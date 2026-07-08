#include "test01.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    test01 window;

    //尺寸 + 标题 + 名称
    window.resize(1000, 600);
    window.setWindowTitle(QStringLiteral("widget窗口的标题"));

    //window.setParent(&app);
    /*
      核心错误：类型不匹配
        app 是 QApplication 对象，QApplication 不是 QWidget 子类
        setParent() 只接收 QWidget* 类型父对象，传 QApplication* 参数类型非法，编译器直接报错

        修正方案
        完全删掉这一行！
        顶层窗口（独立弹窗 QWidget/QMainWindow）不需要把 QApplication 设为父，
        Qt 应用会自动管理生命周期，这行代码本身毫无意义。
    */

    //window.setObjectName("window")；
    /*
        void setObjectName(const QString &name);
        你传的是 C 原生 const char* 字符串字面量 "window"，部分 Qt/编译器 环境下会标红提示类型隐式转换 警告/报错
    */
    //window.setObjectName(QString("window"));
    window.setObjectName(QStringLiteral("window"));


    window.show();
    return app.exec();
}
