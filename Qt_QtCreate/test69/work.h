#ifndef WORK_H
#define WORK_H

#include <QObject>
#include <shared_mutex>   // std::shared_mutex, std::shared_lock
#include <mutex>          // std::unique_lock

class Work : public QObject
{
    Q_OBJECT
public:
    explicit Work(const QString &name, QObject *parent = nullptr);

public slots:
    // 读操作：使用 std::shared_lock（共享锁），多个读者可同时进入
    void doRead();
    // 写操作：使用 std::unique_lock（独占锁），写时阻塞所有读者和其他写者
    void doWrite();

signals:
    void workFinished(const QString &msg);

private:
    static std::shared_mutex s_mutex;   // C++17 读写锁
    static int s_data;                  // 被保护的共享资源

    QString m_name;                     // 工作者名称（用于日志输出）
};

#endif
