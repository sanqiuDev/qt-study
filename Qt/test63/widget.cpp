#include "widget.h"
#include "ui_widget.h"

#include <QTimerEvent>
#include <QDebug>

#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //ok今天我们的任务是：定时器
    /*
        普通 UI 倒计时、简单定时任务 → 用 QTimer
        代码干净、不容易忘释放、可维护性好

        高频刷新（比如 10ms、20ms）、资源紧张、追求极致性能 → 用 timerEvent
        开销小、更接近底层，适合简单、密集定时
    */

    //QTimer 方式（第一个倒计时）

    //1.首先先创建定时器
    time = new QTimer(this);

    //2.将定时器的timeout信号和lcdNumber数字显示的槽函数进行绑定
    connect(time,&QTimer::timeout,this,&Widget::handle);

    //3.启动定时器
    time->start(1000);



    //----------------------------v-----------------------------------
    //timerEvent 方式（第二个倒计时）

    //开启定时器事件
    timeID = this->startTimer(2000); //注意：这里的这个timeID是定时器身份标识

}

Widget::~Widget()
{
    delete ui;
}

void Widget::handle()
{
    //1.获取lcdNumber控件显示的值并进行判断
    int value = ui->lcdNumber->intValue();   //注意细节：1）intValue的返回值是int类型的   2）value的返回值是double类型的
    if(value<=0)
    {
        time->stop();
        return;
    }

    //2.调整lcdNumber控件上战展示的数字
    ui->lcdNumber->display(value-1);
}


//重写：“定时器事件”的虚函数
void Widget::timerEvent(QTimerEvent *event)
{
    //1.判断触发这个定时器事件的是不是我们的定时器
    if(event->timerId() != this->timeID)
    {
        return;
    }

    //2.获取控件上显示的值并进行判断
    int value = ui->lcdNumber_2->intValue();
    if(value<=0)
    {
        this->killTimer(this->timeID);
        return;
    }

    //3.调整控件上展示的数字
    ui->lcdNumber_2->display(value-1);
}














