#include "test17.h"
#include <QLabel>
#include <QDebug>

test17::test17(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    //这里我们来学习一个新的函数：findChildren
    /*
        findChildren 是 QObject 的成员函数，用来递归查找子对象，按类型 + 名字搜索子控件/子对象，Qt UI 开发非常常用。

         头文件：#include <QObject>
         所有继承 QObject 的类（QWidget、QLabel、QMainWindow 等）都可以调用。
    
    */

    //第一种查找方式：不指定控件名称
    QList<QLabel*> labelList = this->findChildren<QLabel*>(); //注意这里this是test17，public QMainWindow，我们要递归查找它上面的子对象
    //注意几点：
    /*
        1.就是<>中放的是你想要查找的控件的类型  
        2.后面还有一个函数调用参数()我们就不填了
        3.会找到很多个控件所以返回值就用 QList<找的类型*>就行了
    */
    qDebug() << "QLabel控件一共有多少个：" << labelList.size();

    //第二种查找方式：指定控件名称
    QList<QLabel*> labelList2 = this->findChildren<QLabel*>("label");
    qDebug() << "名字叫做label的控件有几个：" << labelList2.size();

}

test17::~test17()
{}

