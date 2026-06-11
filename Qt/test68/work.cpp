#include "work.h"

int Work::counter = 0;

//尝试不同锁
//std::mutex Work::_mutex1; //注意：像是互斥锁这种不需要初始化，直接照抄就行，然后给对象补充一个（类名::）
//std::mutex *Work::_mutex2 = new std::mutex();
//std::mutex Work::_mutex3;  //虽然锁他不需要什么值来进行初始化，但是它是一个静态的锁就必须要在类外照抄一下
std::mutex Work::_mutex4;

Work::Work(QObject *parent) : QObject(parent)
{
}

void Work::doWork()
{

    for(int i = 0; i < 50000; i++)
    {
       //_mutex1.lock();
       //_mutex2->lock();
       //std::lock_guard<std::mutex> lock(_mutex3);
        std::unique_lock<std::mutex> lock(_mutex4);


        // 不加锁：多个线程同时读写 counter，造成线程安全问题
        counter++;

       //_mutex1.unlock();
       //_mutex2->unlock();

    }

    emit workFinished(counter);
}
