#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_startButton_clicked();

private:
    void producer();
    void consumer();

    Ui::Widget *ui;

    std::thread m_producerThread;
    std::thread m_consumerThread;
    std::mutex m_mutex;
    std::condition_variable m_cv;
    std::queue<int> m_queue;
    bool m_done = false;
    bool m_stopped = false;
};
#endif
