#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //还是一样的这里我们来演示水平布局管理器的使用

    //1.先定义一些Box的控件
    QPushButton *pushButton1 = new QPushButton(this);
    QPushButton *pushButton2 = new QPushButton(this);
    QPushButton *pushButton3 = new QPushButton(this);

    //2.定义水平布局管理器
    QHBoxLayout *layout = new QHBoxLayout(this);


    //3.将Box控件都添加到水平布局管理器中
    layout->addWidget(pushButton1);
    layout->addWidget(pushButton2);
    layout->addWidget(pushButton3);

    //4.将布局管理器添加
    this->setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}




