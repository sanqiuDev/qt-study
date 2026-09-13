#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    work1 = new Work();
    work2 = new Work();
    thread1 = new QThread();
    thread2 = new QThread();

    work1->moveToThread(thread1);
    work2->moveToThread(thread2);
    /*
       注意：我第一次写错是因为 ---> 只定义了一个 “工作对象指针” 然后这里的就只能写成
        work1->moveToThread(thread1);
        work1->moveToThread(thread2);
    原代码问题：work->moveToThread(thread1) 后马上 moveToThread(thread2)，
    导致 Work 对象最终只存在于 thread2
    新代码：
        两个独立的 Work 对象（work1 / work2），各自移动到一个线程
        共享一个 static int counter，两个线程各对 counter 执行 50000 次 counter++
        不加锁：counter++ 非原子操作（读-改-写三步），两个线程同时操作时会发生竞态条件，导致最终结果 小于 100000
    */

    connect(thread1, &QThread::started, work1, &Work::doWork);
    connect(thread2, &QThread::started, work2, &Work::doWork);

    connect(work1, &Work::workFinished, this, &Widget::handle);
    connect(work2, &Work::workFinished, this, &Widget::handle);

    connect(thread1, &QThread::finished, work1, &Work::deleteLater);
    connect(thread2, &QThread::finished, work2, &Work::deleteLater);
    connect(thread1, &QThread::finished, thread1, &QThread::deleteLater);
    connect(thread2, &QThread::finished, thread2, &QThread::deleteLater);

    thread1->start();
    thread2->start();
}

Widget::~Widget()
{
    thread1->quit();
    thread1->wait();

    thread2->quit();
    thread2->wait();

    delete ui;
}

void Widget::handle(int num)
{
    ui->label->setText(QString::number(num));
}
