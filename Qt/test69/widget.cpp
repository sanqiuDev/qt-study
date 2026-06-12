#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // ========== 创建工作者对象 ==========
    m_readWork1 = new Work("读者1");
    m_readWork2 = new Work("读者2");
    m_readWork3 = new Work("读者3");
    m_writeWork = new Work("写者");

    // ========== 创建线程 ==========
    m_readThread1 = new QThread(this);
    m_readThread2 = new QThread(this);
    m_readThread3 = new QThread(this);
    m_writeThread = new QThread(this);

    // 将工作者移动到对应线程（每个工作者在独立的线程中运行）
    m_readWork1->moveToThread(m_readThread1);
    m_readWork2->moveToThread(m_readThread2);
    m_readWork3->moveToThread(m_readThread3);
    m_writeWork->moveToThread(m_writeThread);

    // ========== 连接信号槽 ==========
    // 所有工作者完成后更新界面日志
    connect(m_readWork1, &Work::workFinished,this, &Widget::onWorkFinished);
    connect(m_readWork2, &Work::workFinished,this, &Widget::onWorkFinished);
    connect(m_readWork3, &Work::workFinished,this, &Widget::onWorkFinished);
    connect(m_writeWork, &Work::workFinished,this, &Widget::onWorkFinished);

    // 界面按钮
    connect(ui->btnRead, &QPushButton::clicked,this, &Widget::onStartRead);
    connect(ui->btnWrite, &QPushButton::clicked,this, &Widget::onStartWrite);
    connect(ui->btnAll, &QPushButton::clicked,this, &Widget::onStartAll);

    // 线程结束时自动清理工作者对象
    connect(m_readThread1, &QThread::finished,m_readWork1, &QObject::deleteLater);
    connect(m_readThread2, &QThread::finished,m_readWork2, &QObject::deleteLater);
    connect(m_readThread3, &QThread::finished,m_readWork3, &QObject::deleteLater);
    connect(m_writeThread, &QThread::finished,m_writeWork, &QObject::deleteLater);

    // ========== 启动线程 ==========
    m_readThread1->start();
    m_readThread2->start();
    m_readThread3->start();
    m_writeThread->start();
}

Widget::~Widget()
{
    // 停止所有线程
    m_readThread1->quit(); m_readThread1->wait();
    m_readThread2->quit(); m_readThread2->wait();
    m_readThread3->quit(); m_readThread3->wait();
    m_writeThread->quit(); m_writeThread->wait();
    delete ui;
}

// 启动 3 个读者同时读取
void Widget::onStartRead()
{
    QMetaObject::invokeMethod(m_readWork1, "doRead", Qt::QueuedConnection);
    QMetaObject::invokeMethod(m_readWork2, "doRead", Qt::QueuedConnection);
    QMetaObject::invokeMethod(m_readWork3, "doRead", Qt::QueuedConnection);
}
/*
    让对象 m_readWork1，在它所属的线程里，安全地调用它的 doRead 槽函数，调用方式是队列方式（QueuedConnection）

    为什么要用它？（解决什么痛点）
        Qt 有一个硬性规则：（不满足的话，会有线程安全问题）+
            只能在创建控件的线程里操作控件 ---> 简单点说就是：只有主线程可以创建控件和操作控件
            也不能在一个线程里直接调用另一个线程对象的方法 ---> 简单说就是：主线程不能调用移交给子线程的任务对象的成员函数

        你这段代码的典型场景是：
        m_readWork1、m_readWork2、m_readWork3 这几个对象，都已经 moveToThread 到了后台线程里
        你在主线程里，想触发这些后台对象执行 doRead 任务
        直接调用 m_readWork1->doRead() 是不安全的，因为它的对象在别的线程里
        用 invokeMethod + Qt::QueuedConnection，就能让 Qt 帮你把调用 “投递” 到对象所属的线程里执行，完全线程安全


    第三个参数 Qt::QueuedConnection：连接类型，这里是队列方式
    它的效果是：不会立刻执行，而是把调用请求放到目标对象的线程事件循环里排队
    等目标线程有空了，再在它自己的线程里执行 doRead
    这是跨线程调用的标准安全方式
*/

// 启动 1 个写者写入
void Widget::onStartWrite()
{
    QMetaObject::invokeMethod(m_writeWork, "doWrite", Qt::QueuedConnection);
}

// 同时启动所有读者和写者，观察读写锁的互斥行为
void Widget::onStartAll()
{
    onStartRead();
    onStartWrite();
}

// 在日志列表中添加一条消息
void Widget::onWorkFinished(const QString &msg)
{
    ui->listWidget->addItem(msg);
    ui->listWidget->scrollToBottom();
}
/*
    它的作用是：让 QListWidget 控件自动滚动到最底部，把最新添加的内容显示出来。
它解决的痛点是什么？
    想象一下你在做一个聊天窗口或者日志窗口：
    你不断往 listWidget 里添加新消息/新日志（比如用 addItem()）
    当内容超出控件高度时，会出现滚动条
    默认情况下，滚动条会停留在原地，新内容在底部，你看不到，需要手动拉到底部
    调用 scrollToBottom() 后，控件会自动把滚动条滑到最下面，让用户直接看到最新的一条
*/
