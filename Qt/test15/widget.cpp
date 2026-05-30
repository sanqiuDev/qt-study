#include "widget.h"
#include "ui_widget.h"


#include <QDebug>
#include <QResizeEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    //实现图片动态拉伸
    //1.将标签设置的和窗口一样大
    ui->label->setGeometry(0,0,this->geometry().width(),this->geometry().height());

    //2.将创建图片添加到标签中
    QPixmap pixmap(":/cat.png");
    ui->label->setPixmap(pixmap);


    //3.设置图片为可拉伸的状态
    ui->label->setScaledContents(true);

}

Widget::~Widget()
{
    delete ui;
}


//4. 需要重写父类QWidget中的resizeEvent方法
void Widget::resizeEvent(QResizeEvent *event)  //注意：这里需要添加头文件：#include <QResizeEvent>
{
    qDebug()<<event->size();

    ui->label->setGeometry(0,0,event->size().width(),event->size().height());
}


























