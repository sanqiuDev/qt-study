#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //默认密文显示
    ui->lineEdit->setEchoMode(QLineEdit::Password);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_checkBox_toggled(bool checked) //简单说明一下这个信号：就是选中状态的时候会触发
{
    if(checked==true)
    {
        ui->lineEdit->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->lineEdit->setEchoMode(QLineEdit::Password);
    }
}
