#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include "work.h"

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
    // 按钮响应
    void onStartRead();
    void onStartWrite();
    void onStartAll();
    // 工作者完成时更新 UI
    void onWorkFinished(const QString &msg);

private:
    Ui::Widget *ui;

    // 3 个读者 + 1 个写者
    Work *m_readWork1;
    Work *m_readWork2;
    Work *m_readWork3;
    Work *m_writeWork;

    QThread *m_readThread1;
    QThread *m_readThread2;
    QThread *m_readThread3;
    QThread *m_writeThread;
};

#endif // WIDGET_H
