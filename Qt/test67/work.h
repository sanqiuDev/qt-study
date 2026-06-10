#ifndef WORK_H
#define WORK_H

#include <QObject>

class Work : public QObject
{
    Q_OBJECT
public:
    explicit Work(QObject *parent = nullptr);

    //对于这个work.h文件我们需要三样东西：
    /*
        1. 槽函数（用来进行处理耗时任务）
        2. 自定义的信号（用来进行通知）
    */
public slots:
    //1.处理耗时的任务
    void doWork();

signals:
    //1.通知UI界面更新
    void sendNum(int num);

    //2.通知任务的终止
    void workFinished();


};

#endif // WORK_H
