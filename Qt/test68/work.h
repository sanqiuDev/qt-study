#ifndef WORK_H
#define WORK_H

#include <QObject>
#include <mutex>

class Work : public QObject
{
    Q_OBJECT
public:
    explicit Work(QObject *parent = nullptr);

public slots:
    void doWork();

signals:
    void workFinished(int num);

private:
    static int counter;  //全局静态变量（临界资源），只有临界资源多线程并发访问才会出现线程安全问题（局部变量不是临界资源）

    /* 注意细节：
        静态成员变量：是必须类外定义和初始化，不是推荐，是强制要求
                    唯一例外是 const static 整型或 constexpr static 可以在类内直接初始化
        静态成员函数：类内外都可以定义，没有强制要求
    */
    //定义互斥锁对象指针
    //std::mutex _mutex1;
    /*
        因为你的 _mutex1 是非静态成员变量，每个 Work 对象有自己独立的 _mutex1
            work1->_mutex1   ← thread1 锁的是这个
            work2->_mutex1   ← thread2 锁的是这个
        两个线程锁的是不同的互斥量，等于没锁，
        简单说：保护共享资源（static counter）的锁，自身也必须是共享的（static）
        两个线程各锁各的，就像两个人各拿一把锁去锁同一扇门——根本锁不住。
        static 的本质就是把原本各有一份的东西变成共享一份，这样两个线程才能用同一把锁来保护同一个临界区。

    */
    //static std::mutex _mutex1;



    //static std::mutex *_mutex2;

    //使用“锁守卫”
    //static std::mutex _mutex3;

    //使用“独占锁”
    static std::mutex _mutex4;
    /*
        std::lock_guard：极简版锁，构造时上锁，析构时解锁，中途不能解锁/重新上锁，也不能手动控制
        std::unique_lock：完整版锁，除了自动上锁/解锁，还支持中途解锁、重新上锁、延迟上锁、条件变量配合等操作，开销略高

        std::lock_guard  全称：锁守卫/标准写法直接读：lock_guard
        std::unique_lock 全称：独占锁/标准写法直接读：unique_lock
    */


    /* 最简选型口诀：
        只锁单个 mutex、逻辑简单 → lock_guard
        需要中途解锁 / 条件变量 → unique_lock
        读多写少、读写分离 → shared_lock + shared_mutex
        需要同时锁多个 mutex 防死锁 → scoped_lock（C++17+）
    */
};

#endif // WORK_H
