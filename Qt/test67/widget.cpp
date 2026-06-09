#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    //之前我们是使用 “继承QThread类重写其虚函数run来创建线程” ，接下里我们换一种创建线程的方法
    //任务：使用：moveToThread创建线程
    /*
        先记住一句话：moveToThread = 把一个普通对象，丢进子线程里运行。
            不用继承 QThread
            不用重写 run ()
            所有耗时任务写在普通槽函数里
            信号触发 → 槽函数自动在子线程运行


    */


}

Widget::~Widget()
{
    delete ui;
}

