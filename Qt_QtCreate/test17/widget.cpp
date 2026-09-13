#include "widget.h"
#include "ui_widget.h"


#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //1.设置初始值
    ui->lcdNumber->display(10);

    //2..创建一个定时器对象
    time = new QTimer(this);

    //2.将“定时七器的信号timeout和槽函数”绑定
    connect(time,&QTimer::timeout,this,&Widget::handle);
    /*
        timeout 是 QTimer 发射的一个信号
            含义：定时器时间到了
            触发：timer->start(1000) 后，每隔 1 秒自动发出一次
            作用：用来做周期性任务、倒计时、状态轮询等
        一句话：Qt 里 timeout = 闹钟响了。
    */

    //4.启动定时器
    time->start(1000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handle()
{
    //1.先拿到lcdNumber这个控件中数字，判断是否要停止定时器
     int number=ui->lcdNumber->intValue();
     if(number<=0)
     {
         time->stop();
         return;
     }

     //2.展示数字-1后的值
     ui->lcdNumber->display(number -1);
}
