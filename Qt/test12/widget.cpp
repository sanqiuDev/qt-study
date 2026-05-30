#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 也可以提前为它添加默认的选项
    //1.直接默认指定它的性别是未知
    ui->radioButton_3->setChecked(true);
    ui->lineEdit->setText("您选择的性别是：未知");

    //2.禁用其他的选项
    ui->radioButton_4->setCheckable(false);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_radioButton_clicked()
{
    ui->lineEdit->setText("您选择的性别是：男");
}

void Widget::on_radioButton_2_clicked()
{
    ui->lineEdit->setText("您选择的性别是：女");
}

void Widget::on_radioButton_3_clicked()
{
    ui->lineEdit->setText("您选择的性别是：未知");
}
