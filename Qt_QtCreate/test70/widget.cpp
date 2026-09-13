#include "widget.h"
#include "ui_widget.h"

#include <QMetaObject>
#include <chrono>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    m_stopped = true;
    m_cv.notify_all();
    if (m_producerThread.joinable())
        m_producerThread.join();
    if (m_consumerThread.joinable())
        m_consumerThread.join();
    delete ui;
}

void Widget::on_startButton_clicked()
{
    ui->startButton->setEnabled(false);
    ui->logEdit->clear();

    // 如果上次线程还在运行，先安全停止
    m_stopped = true;
    m_cv.notify_all();
    if (m_producerThread.joinable())
        m_producerThread.join();
    if (m_consumerThread.joinable())
        m_consumerThread.join();

    m_done = false;
    m_stopped = false;

    m_producerThread = std::thread(&Widget::producer, this);
    m_consumerThread = std::thread(&Widget::consumer, this);
}

void Widget::producer()
{
    for (int i = 0; i < 10; ++i) {
        if (m_stopped) break;

        // 模拟生产耗时
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        {
            std::lock_guard<std::mutex> lock(m_mutex);
            m_queue.push(i);
        }   // 离开作用域时自动解锁

        m_cv.notify_one();  // 通知消费者

        QMetaObject::invokeMethod(this, [this, i]() {
            ui->logEdit->append(QString("[生产者] 生产了: %1").arg(i));
        }, Qt::QueuedConnection);
    }

    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_done = true;
    }
    m_cv.notify_one();

    QMetaObject::invokeMethod(this, [this]() {
        ui->logEdit->append("[生产者] 生产完成!");
    }, Qt::QueuedConnection);
}

void Widget::consumer()
{
    while (true) {
        int value = 0;
        bool hasData = false;

        {
            std::unique_lock<std::mutex> lock(m_mutex);

            // wait 自动解锁，被唤醒后重新加锁；谓词防止虚假唤醒
            m_cv.wait(lock, [this]() {
                return !m_queue.empty() || m_done || m_stopped;
            });

            if (m_stopped) break;

            if (!m_queue.empty()) {
                value = m_queue.front();
                m_queue.pop();
                hasData = true;
            } else if (m_done) {
                break;  // 生产结束且队列为空，退出
            }
        }   // 离开作用域自动解锁

        if (hasData) {
            // 模拟消费耗时
            std::this_thread::sleep_for(std::chrono::milliseconds(800));

            QMetaObject::invokeMethod(this, [this, value]() {
                ui->logEdit->append(QString("[消费者] 消费了: %1").arg(value));
            }, Qt::QueuedConnection);
        }
    }

    QMetaObject::invokeMethod(this, [this]() {
        ui->logEdit->append("[消费者] 消费完成!");
        ui->startButton->setEnabled(true);
    }, Qt::QueuedConnection);
}

