#include "widget.h"
#include "ui_widget.h"

#include <QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //再来手动演示一下代码添加下拉框中的选项
    ui->comboBox->addItem("培根蔬萃双层牛堡");

    //1.设置整数调节框的范围
    ui->spinBox->setRange(1,100);
    ui->spinBox_2->setRange(1,100);
    ui->spinBox_3->setRange(1,100);

    //2.设置整数调节框的当前值
    ui->spinBox->setValue(1);
    ui->spinBox_2->setValue(1);
    ui->spinBox_3->setValue(1);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    qDebug()<<"用户下单了："<<Qt::endl
            <<ui->comboBox->currentText()<<ui->spinBox->value()<<"个"<<Qt::endl
            <<ui->comboBox_2->currentText()<<ui->spinBox_2->value()<<"个"<<Qt::endl
            <<ui->comboBox_3->currentText()<<ui->spinBox_3->value()<<"个"<<Qt::endl;
}













