#include "widget.h"
#include "ui_widget.h"
#include "thread.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //之前我们使用：定时器/事件 分别实现了“倒计时”的案例
    //今天我们来使用 “多线程” 来实现倒计时的案例

    //1.创建
    //thread = new Thread(this);  //没有有参的构造函数，我们也可以使用无参的
    thread = new Thread;
    thread->setParent(this); //记得再手动设置一个父对象

    //2.绑定
    connect(thread,&Thread::notify,this,&Widget::handle);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater); //安全销毁；

    //3.启动进程
    thread->start();

}

Widget::~Widget()
{
    //注意：线程销毁细节
    if (thread->isRunning())
    {
        thread->quit();
        thread->wait();
    }

    delete ui;
}


void Widget::handle()
{
    //1.获取当前控件的值
    int value = ui->lcdNumber->intValue();
    if(value<=0)
    {
        // 停止线程！！！
        thread->quit();
        thread->wait();

        return;
    }

    //2.重新设置控件展示的值
    ui->lcdNumber->display(value-1);
}

