#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //今天我们实现一个这样的操作就是：鼠标点击不同按钮可以设置不同文章标题
    //其实这个功能是简单的，但是我们这次要有要求就是
    //点击信号的处理函数里面不能使用setText()，也就是不能设置标题

    connect(this,&Widget::mySignal,this,&Widget::handle_title);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::handle_title(const QString &text)
{
    ui->lineEdit->setText(text);
}

void Widget::on_pushButton_clicked()
{
//    ui->lineEdit->setText("皮卡丘");
    emit mySignal("皮卡丘");

}

void Widget::on_pushButton_2_clicked()
{
//  ui->lineEdit->setText("小熊虫");
      emit mySignal("小熊虫");
}

void Widget::on_pushButton_3_clicked()
{
//   ui->lineEdit->setText("罗小黑");
       emit mySignal("罗小黑");
}



