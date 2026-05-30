#include "widget.h"
#include "ui_widget.h"



#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    /*
        今天我们主要来实现lambda的使用，也就是不单独再去写什么槽函数了，而是直接在connect函数中定义lambda函数
    */

    //1. 先来简单的使用一下lambda
    QPushButton *pushButton = new QPushButton(this);
    pushButton->setText("用来测试lambda表达式的使用");
    pushButton->resize(300,100);
    pushButton->move(150,150);

    connect(pushButton,&QPushButton::clicked,this,
            [pushButton]()
    {
        if(pushButton->text()=="用来测试lambda表达式的使用")
            pushButton->setText("内容修改成功");
    }
    );

    /*
       在Qt中写lambda表达式的时候，捕获部分一般都是
           1. 手动指定控件捕获  2. 值捕获
       Qt中基本上不用&捕获
    */
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_1_clicked()
{
    ui->pushButton_1->resize(200,200);
}



void Widget::on_pushButton_2_clicked()
{
    if(ui->pushButton_1->isEnabled())
    {
        ui->pushButton_1->setEnabled(false);
    }
    else
    {
        ui->pushButton_1->setEnabled(true);
    }
}
