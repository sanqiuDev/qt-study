//#include "widget.h"

//#include <QApplication>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    Widget w;
//    w.show();
//    return a.exec();
//}


//第一步：包含头文件
#include "widget.h"
#include <QApplication>

//第二步：编写main函数
int main(int argc,char *argv[])
{
    //1.创建QApplication应用程序对象
    QApplication a(argc,argv);

    //2.创建自定义的主窗口Widget类实例
    Widget w;

    //3.调用QWidget基类的show方法展示主窗口
    w.show();

    //4.启动Qt应用程序的主事件循环，并阻塞当前线程
    return a.exec();
}
