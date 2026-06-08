#include "widget.h"
#include "ui_widget.h"

#include <QLabel>
#include <QDebug>
#include <QMouseEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setMouseTracking(true);
    /* 对于构造函数中的这行代码：setMouseTracking (true)
        不加 → 只有按住鼠标移动才触发 move
        加了 → 只要在控件上移动就触发 move
    */
}

/*
   这里做一个简单的说明：
       1. 你在哪个控件的源文件中：“重写虚函数”，那么这些事件就是针对哪个控件的
*/

Widget::~Widget()
{
    delete ui;
}


//实现：“进入事件”的虚函数重写
void Widget::enterEvent(QEvent *event)
{
    (void)event;
    qDebug()<<"鼠标进入了窗口";
}

//实现：“鼠标点击事件”的虚函数重写
void Widget::mousePressEvent(QMouseEvent *event)
{
    (void)event;
    qDebug()<<"鼠标点击了窗口";
}

//实现：“鼠标移动事件”的虚函数重写
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug()<<"鼠标进行了移动，鼠标的位置是："<<event->globalX()<<","<<event->globalY();
}



