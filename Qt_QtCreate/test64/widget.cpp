#include "widget.h"
#include "ui_widget.h"

#include <QMoveEvent>
#include <QDebug>
#include <QResizeEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


//重写：“窗口/控件的移动事件”的虚函数
void Widget::moveEvent(QMoveEvent *event)
{
     qDebug()<<event->pos();
}


//重写：“窗口/控件的尺寸变化事件”的虚函数
void Widget::resizeEvent(QResizeEvent *event)
{
    qDebug()<<event->size();
}

