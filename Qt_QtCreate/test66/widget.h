#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "thread.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void handle();

private:
    Ui::Widget *ui;

    //Thread thread;
    /*
       它能运行，有两个前提：
        thread 是 Widget 的成员变量，生命周期和 Widget 一样长，不会半路被销毁；
        线程对象 thread 只要不被提前析构，就能正常工作。
    所以从 “能不能跑” 的角度，它是没问题的。
    */
    Thread *thread;
};
#endif // WIDGET_H
