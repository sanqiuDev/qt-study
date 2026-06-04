#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //来尝试使用纯代码的方式实现：控件的垂直布局
    //1.首先我们先来定义一些控件
    QPushButton *pushButton1 = new QPushButton();
    QPushButton *pushButton2 = new QPushButton();
    QPushButton *pushButton3 = new QPushButton();


    //2.然后定义垂直布局管理器
    QVBoxLayout  *layout = new QVBoxLayout();

    //3.将按钮控件都添加到竖直布局管理器中
    layout->addWidget(pushButton1);
    layout->addWidget(pushButton2);
    layout->addWidget(pushButton3);

    //4.将竖直控件管理器添加到Widget窗口上
    this->setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}

