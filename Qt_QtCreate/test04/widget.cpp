#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //今天我们实现的一个任务就是：点击一个按钮可以修改另一个按钮的功能


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    disconnect(ui->pushButton_2,&QPushButton::clicked,this,&Widget::on_pushButton_2_clicked);

    ui->pushButton_2->setText("技能：变大");

    connect(ui->pushButton_2,&QPushButton::clicked,this,&Widget::on_pushButton_22_clicked);
}

void Widget::on_pushButton_2_clicked()
{
    ui->pushButton_2->setGeometry(450,230,ui->pushButton_2->width(),ui->pushButton_2->height());
}
void Widget::on_pushButton_22_clicked()
{
    ui->pushButton_2->setText("");
    ui->pushButton_2->resize(200,200);
}
