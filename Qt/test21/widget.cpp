#include "widget.h"
#include "ui_widget.h"


#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //根据前面所学我们先来初始化一下这两个单行输入框
    ui->password->setPlaceholderText("请输入密码");
    ui->password->setClearButtonEnabled(true);
    ui->password->setEchoMode(QLineEdit::Password);


    ui->password_again->setPlaceholderText("请再次输入密码");
    ui->password_again->setClearButtonEnabled(true);
    ui->password_again->setEchoMode(QLineEdit::Password);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::compare() //注意：这个函数似乎也不是槽函数，但是它要在头文件中进行声明
{
    //细节注意一下：就是QLabel没有判断控件中是否为空的函数，但是我们可以：提取控件的字符串 -> QString -> isEmpty
    const QString str1 = ui->password->text();
    const QString str2 = ui->password_again->text();
    if(str1.isEmpty()&&str2.isEmpty())
    /*
        注意这里判断的细节：
            1. 两次输入的内容不同
            2. 两次输入的内容相同 (还要排除两次密码都为空的情况)

    */
    {
        qDebug()<<"两次输入的密码都为空";
    }

    //
    else if(str1==str2)
    {
        qDebug()<<"两次输入的密码相同";
    }
    else
    {
        qDebug()<<"两次输入的密码不相同";
    }
}

void Widget::on_password_textEdited(const QString &arg1)
{
    this->compare(); //直接调用compare函数，相当于是将作为了一个信号的转发工具
    /*
        按理来说：那么我们为什么不直接将：textEdited信号和函数commpare进行绑定呢
        因为使用connect只能将：某一个控件和信号进行绑定
    */
}

void Widget::on_password_again_textEdited(const QString &arg1)
{
    this->compare();
}
