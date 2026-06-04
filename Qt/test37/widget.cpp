#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //1.先实现垂直的布局
    QVBoxLayout *layout1 = new QVBoxLayout(); //注意细节：不传this
    QPushButton *pushButton1 = new QPushButton("1",this);   //注意顺序：文字 + 父窗口
    QPushButton *pushButton2 = new QPushButton("2",this);

    layout1->addWidget(pushButton1);
    layout1->addWidget(pushButton2);


    //2.再实现水平的布局
    QHBoxLayout *layout2 = new QHBoxLayout(); //注意细节：不传this
    QPushButton *pushButton3 = new QPushButton("3",this);
    QPushButton *pushButton4 = new QPushButton("4",this);

    layout2->addWidget(pushButton3);
    layout2->addWidget(pushButton4);


    //3.最后再将 水平布局添加到竖直布局中
    layout1->addLayout(layout2);

     this->setLayout(layout1); //仅顶层布局调用一次
//    this->setLayout(layout2);

}

Widget::~Widget()
{
    delete ui;
}

