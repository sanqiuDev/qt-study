#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>
#include <QGridLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //使用QGridLayout网格布局：
    //1. 网格布局管理器
    QGridLayout *layout = new QGridLayout(); //不要使用this

    //2. 准备四个按钮
    QPushButton *pushButton1 = new QPushButton("1",this);
    QPushButton *pushButton2 = new QPushButton("2",this);
    QPushButton *pushButton3 = new QPushButton("3",this);
    QPushButton *pushButton4 = new QPushButton("4",this);

    //3.按钮添加到网格布局管理器中
    layout->addWidget(pushButton1,0,0);
    layout->addWidget(pushButton2,0,1);
    layout->addWidget(pushButton3,1,0);
    layout->addWidget(pushButton4,1,1);

    //4.将网格布局管理器添加到窗口上
    this->setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}

