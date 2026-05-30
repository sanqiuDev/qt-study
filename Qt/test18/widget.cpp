#include "widget.h"
#include "ui_widget.h"


#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //1.创建定时器
    time = new QTimer();

    //2.将定时器的timeout信号和槽函数关联起来
    connect(time,&QTimer::timeout,this,&Widget::handle);

    //3.启动定时器
    time->start(1000);
}

Widget::~Widget()
{
    delete ui;
}

//实现超函数
void Widget::handle()
{
    //1.获取当前进度条的值，并判断是否要结束槽函数
    int value = ui->progressBar->value();
    if(value>=100)
    {
        time->stop();
        return;
    }

    //2.展示当前数字+1的进度
    ui->progressBar->setValue(value+1);
}
