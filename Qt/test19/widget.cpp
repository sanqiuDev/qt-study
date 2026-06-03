#include "widget.h"
#include "ui_widget.h"

//#include <QDebug>
//#include <QProgressBar>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //我们再来尝试实现一次进度条

    //首先我们需要一个计时器用来定时触发指定的槽函数
    //1. 创建对象指针 --> （全局创建，局部赋值）
    time =new QTimer(this);

    //2.将 完成进度的槽函数 和 定时器的信号进行绑定
    connect(time,&QTimer::timeout,this,&Widget::handle);

    //3. 启动定时器
    time->start(100);
}

Widget::~Widget()
{
    delete ui;

}


void Widget::on_calendarWidget_selectionChanged()
{
    //注意：就是了类似于pushButton的信号clicked信号一样
    //日历控件也有自己的信号，这里我们演示使用的就是：selectionChanged信号

    //这个信号触发，将会直接调用与其绑定的槽函数

    //1.第一步：先拿到用户设置的日期对象
    QDate date = ui->calendarWidget->selectedDate();

    //qDebug()<<date;

    //2.第二步：将日期对象转化的字符串并将其添加到
    ui->label->setText(date.toString());
}

/*
void Widget::on_progressBar_valueChanged(int value)
{
    //就像的日历一样我们也是根据进度条特有信号，绑定槽函数
    //日历：选择日期(selectionChanged)
    //进度条：进度值发生变化(valueChanged) ---> 信号触发



}
*/

//需要注意的是；进度条的实现并不是根据进度条控件内置的什么信号然后绑定什么槽函数实现的
//因为我们想要进度体是每隔1秒钟的时间进度就增加1，所以触发进度发生改变的并不是什么信号
//准确来说：计时器

void Widget::handle()
{
    //1.
    int value = ui->progressBar->value();
    if(value>=100)
    {
        time->stop();
        return;
    }

    //2.
    ui->progressBar->setValue(value+1);
}












