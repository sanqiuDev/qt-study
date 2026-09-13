#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置水平滑动条
    ui->horizontalSlider->setRange(100,1000);
    ui->horizontalSlider->setValue(400);
    ui->horizontalSlider->setSingleStep(2);


    //设置竖直滑动条
    ui->verticalSlider->setRange(100,1000);
    ui->verticalSlider->setValue(400);      //这个数值：水平/竖直 滑动条设置一样的话 ---> 初始的Widget是一个正方形
    ui->verticalSlider->setSingleStep(2);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_horizontalSlider_valueChanged(int value)
{
    const QRect &rect = this->geometry();
    this->setGeometry(rect.x(),rect.y(),value,rect.height());
}

void Widget::on_verticalSlider_valueChanged(int value)
{
    const QRect &rect = this->geometry();
    this->setGeometry(rect.x(),rect.y(),rect.width(),value);
}
