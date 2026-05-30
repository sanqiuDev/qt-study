#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //这里我们实现一个功能：文本阅读器的日夜间切换

}

Widget::~Widget()
{
    delete ui;
}
//

void Widget::on_pushButton_day_clicked()
{
    //1. 设置窗口的样式
    this->setStyleSheet("background-color:rgb(240,240,240)");

    //2. 设置输入框的样式
    ui->label->setStyleSheet("background-color:white;color:black");

    //3. 设置按钮的样式
    ui->pushButton_day->setStyleSheet("color:black");
    ui->pushButton_night->setStyleSheet("color:black");
}

void Widget::on_pushButton_night_clicked()
{
    //1. 设置窗口的样式
    this->setStyleSheet("background-color:rgb(100,100,100)");

    //2. 设置输入框的样式
    ui->label->setStyleSheet("background-color:black;color:white");

    //3. 设置按钮的样式
    ui->pushButton_day->setStyleSheet("color:white");
    ui->pushButton_night->setStyleSheet("color:white");
}
