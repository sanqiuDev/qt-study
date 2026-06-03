#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
//#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //这里说明一下：对于的输入控件中的QLabel控件，
    //基础：text 和 setText
    //进阶：setPlaceholderText 设置提示信息 setClearButtonEnabled 设置输入框右边自动多出一个 × 清除按钮
    ui->name->setPlaceholderText("请输入的用户名");
    ui->name->setClearButtonEnabled(true);

    ui->password->setPlaceholderText("请输入的密码");
    ui->password->setClearButtonEnabled(true);

    //setEchoMode 设置显示模式
    ui->password->setEchoMode(QLineEdit::Password);


    ui->phone->setPlaceholderText("请输入的电话");
    ui->phone->setClearButtonEnabled(true);

    //setInputMask 设置限制输入框只能按固定格式输入
    /*
        0：必须输入一位数字（0~9），不能输字母、符号、空格
        -：固定分隔符，界面自动显示，用户无法修改、不能删除
    */
    ui->phone->setInputMask("000-0000-0000");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
   QString  gender = ui->radioButton->isChecked()?"男":"女";
   //注意：这里要判断的是——判断一个指定一个单选框是否被点击了

   qDebug()<<"用户名："<<ui->name->text()<<Qt::endl
           <<"密码："<<ui->password->text()<<Qt::endl
           <<"性别："<<gender<<Qt::endl
           <<"电话："<<ui->phone->text();
}








