#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>
#include <QDebug>
#include <iostream>

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


void Widget::on_button_up_clicked()
{
    //1.第一步：获取当前的位置
    QRect ret = ui->person->geometry();

    //2. 第二步：输出当前的位置
    qDebug()<<ret<<Qt::endl;
    // qDebug()<<ret<<"\n";   注意：就是使用qDebug需要包含头文件<QDebug> ，以及要qDebug的后面要使用()

    //3.第三步：设置新的位置
    ui->person->setGeometry(ret.x(),ret.y()-5,ret.width(),ret.height());
}

void Widget::on_button_left_clicked()
{
    //1.第一步：获取当前的位置
    QRect ret = ui->person->geometry();

    //2. 第二步：输出当前的位置
    qDebug()<<ret<<Qt::endl;

    //3.第三步：设置新的位置
    ui->person->setGeometry(ret.x()-5,ret.y(),ret.width(),ret.height());
}

void Widget::on_button_down_clicked()
{
    //1.第一步：获取当前的位置
    QRect ret = ui->person->geometry();

    //2. 第二步：输出当前的位置
    qDebug()<<ret<<Qt::endl;

    //3.第三步：设置新的位置
    ui->person->setGeometry(ret.x(),ret.y()+5,ret.width(),ret.height());
}

void Widget::on_button_right_clicked()
{
    //1.第一步：获取当前的位置
    QRect ret = ui->person->geometry();

    //2. 第二步：输出当前的位置
    qDebug()<<ret<<Qt::endl;

    //3.第三步：设置新的位置
    ui->person->setGeometry(ret.x()+5,ret.y(),ret.width(),ret.height());
}
