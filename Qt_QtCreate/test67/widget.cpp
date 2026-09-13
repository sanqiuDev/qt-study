#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    /*
        QObject
          ├── QThread            ← 线程控制类
          └── QPaintDevice       ← 抽象绘制基类
                └── QWidget      ← 所有界面组件的基类
                      ├── QMainWindow  ← 主窗口
                      └── QDialog      ← 对话框
    */


    //之前我们是使用 “继承QThread类重写其虚函数run来创建线程” ，接下里我们换一种创建线程的方法
    //任务：使用：moveToThread创建线程
    /*
        先记住一句话：moveToThread = 把一个普通对象，丢进子线程里运行。
            不用继承 QThread
            不用重写 run ()
            所有耗时任务写在普通槽函数里
            信号触发 → 槽函数自动在子线程运行
    */

    //首先我们的第一步是：创建一个【普通工作类】，这个类就是放耗时任务的。
    /* 注意两件事情，分别是：
        1. 创建的这个工作类是继承QObject这个基类的
        2. 创建好的 work.h 和 work.cpp 文件并不会在Qt 项目树里看到。

      核心原因是：Qt Creator 是靠 .pro 文件里的 SOURCES 和 HEADERS 列表来识别文件的：
        你手动创建了 work.h 和 work.cpp，但它们没有被添加到 .pro 文件里
        所以 Qt Creator 不知道这两个文件属于这个项目，自然不会在项目树里显示它们

            1. 打开 test67.pro 文件
            2. 在 SOURCES 和 HEADERS 里，加上你的文件：
            3. 右键项目 → 选择 Run qmake，再构建项目，文件就会显示了
    */



    //第一步：初始化对象指针
    work = new Work();
    thread = new QThread();
    /*
       是的，new Work() 调用的是无参构造函数。
       () 可以省略，写作 new Work;。两者在 Qt 类（有用户定义的默认构造函数）下效果完全相同。
    不过少数场景下有区别：
        - new Work() — 值初始化，对内置类型成员会零初始化
        - new Work — 默认初始化，对内置类型成员不初始化（保留垃圾值）
    但在 Qt 类中几乎都定义了构造函数，所以写不写 () 没区别。

    */

    //第二步：将任务丢给线程
    work->moveToThread(thread);


    //第三步：线程启动结束信号的绑定
    //（1）线程启动信号的绑定
    connect(thread,&QThread::started,work,&Work::doWork); //线程创建完毕直接开始计时的任务

    //1.控件UI更新的信号的绑定
    connect(work,&Work::sendNum,this,&Widget::handle); //注意细节：由于sendNum信号是有参数，所以其绑定的槽函数的参数<=信号的参数个数
    /*
     在 Qt 的信号槽机制中，槽函数的参数可以比信号少，但不能比信号多。
     具体规则：
        1. 槽函数的参数个数 ≤ 信号的参数个数
        2. 槽函数可以省略信号末尾的某些参数（丢弃多余的信号参数）
        3. 对应位置的参数类型必须兼容（允许隐式转换）
     例如：
        signal: sendNum(int a, QString b)
        slot:  onSendNum(int a)                      // OK，丢弃了 QString b
        slot:  onSendNum(int a, QString b)           // OK
        slot:  onSendNum(int a, QString b, double c) // 编译错误，参数过多
    */

    //2.任务结束信号的绑定
    connect(work,&Work::workFinished,thread,&QThread::quit);

    //（2）线程结束的信号的绑定
    connect(thread,&QThread::finished,work,&Work::deleteLater);
    //（3）线程结束的信号的绑定
    connect(thread,&QThread::finished,thread,&QThread::deleteLater);

    /* 格外注意一件事情就是：编译器不会显示后三个参数不写的红线提示
     完整的 connect 函数有 5 个参数（以最完整的指针到成员函数重载为例）：
        参数                  含义
        sender              发送对象
        signal              信号
        receiver            接收对象
        method              槽/可调用对象
        type                连接类型
      常见的省略形式：
        1. 省略 type（最常用）：
            connect(btn, &QPushButton::clicked, this, &MainWindow::onClick);
        2. 同时省略 receiver 和 type，用 functor：
            connect(btn, &QPushButton::clicked, [](){  lambda });
            此时只剩 3 个参数，btn 的生存期就是连接上下文
   */


    //第四步：启动线程
    thread->start();
}

Widget::~Widget()
{
    //因为使用了线程，这里要处理一些线程
    if(thread->isRunning())
    {
        thread->quit();
        thread->wait();
    }

    delete ui;
}


/*
   Qt中widget.cpp文件的任务是：
     1.实现widget.h文件中的槽函数的定义
     2.信号槽的绑定


     //多线程的处理流程：
     1.初始化对象指针
     2.任务丢给线程
     4.绑定线程的启动和结束信号
     3.启动线程
*/

void Widget::handle(int value)
{
    /*无参数版本的handle
    //1.获取控件的内容
    int value = ui->lcdNumber->intValue();
    if(value<=0)
    {
        thread->quit();
        thread->wait();
        return;
    }

    //2.修改控件的展示的内容
    ui->lcdNumber->display(value-1);
    */

    //有参数版本handle
    ui->lcdNumber->display(value);
}

/*
deleteLater、moveToThread这是谁成员函数，QThread和QObject的关系
    deleteLater 和 moveToThread 都是 QObject 的成员函数，不是 QThread 的
    QThread 和 QObject 的关系
        QThread 继承自 QObject，所以 QThread 本身也是一个 QObject
        moveToThread 作用：把一个 QObject（及其子对象）的事件处理移交到指定线程的事件循环。例如：
    Worker *worker = new Worker;       // 主线程创建
    QThread *thread = new QThread;
    worker->moveToThread(thread);      // worker 的事件/槽将在 thread 中执行
    thread->start();

    此时 worker 的 parent 并未改变（parent 仍是主线程的对象），但它的线程亲和性变成了 thread
*/


