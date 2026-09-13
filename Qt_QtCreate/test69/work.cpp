#include "work.h"
#include <QThread>

// ========== 静态成员类外定义（必须） ==========
std::shared_mutex Work::s_mutex;
int Work::s_data = 1000;

Work::Work(const QString &name, QObject *parent)
    : QObject(parent), m_name(name)
{
}

// 读操作：使用 shared_lock（共享锁）
// 多个线程可以同时持有共享锁，互不阻塞。
// 适用于"读多写少"场景，大幅提升并发读取性能。
void Work::doRead()
{
    //1.添加读锁 —— 不阻塞其他读者，但阻塞写者
    std::shared_lock<std::shared_mutex> lock(s_mutex);

    //2.模拟读取耗时
    int val = s_data;
    QThread::msleep(50);

    //3.任务结束发射信号
    emit workFinished(
        QString("[%1] 读取到值: %2").arg(m_name).arg(val));
    /*
        它的作用，是把一个带占位符的字符串模板，填充上变量，生成最终字符串。

    核心：QString::arg() 是干嘛的？
        %1、%2、%3… 是 Qt 字符串里的占位符，代表 “这里要填一个变量”
        .arg(xxx) 就是 “把 xxx 填到下一个 %n 占位符里”
        按调用顺序，第一个 .arg() 填 %1，第二个填 %2，以此类推
    */
}


// 写操作：使用 unique_lock（独占锁）
// 写时必须独占，阻塞所有读者和其他写者，
// 保证写入时数据不会被其他线程同时读/写。
void Work::doWrite()
{
    //1.添加写锁 —— 阻塞所有读者和其他写者
    std::unique_lock<std::shared_mutex> lock(s_mutex);

    //2.进行写入操作
    int old = s_data;
    s_data += 50;
    QThread::msleep(100);

    //3.任务结束之后发射信号
    emit workFinished(
        QString("[%1] 写入: %2 → %3").arg(m_name).arg(old).arg(s_data));
}







