#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //将之前使用QRadioButton实现的一个点餐的界面重新使用QComboBox重新实现一下

    //这里我们还可以手动的为QComboBox控件添加成员
    ui->comboBox->addItem("香辣鸡腿堡");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
//这里要注意细节就是：QComboBox控件显示内容使用的函数是currentText() 而不是我们常见的text
{
    qDebug()<<"用户的点餐是："<<Qt::endl
            <<"汉堡："<<ui->comboBox->currentText()<<Qt::endl
            <<"小食："<<ui->comboBox_2->currentText()<<Qt::endl
            <<"饮料："<<ui->comboBox_3->currentText();
}


















