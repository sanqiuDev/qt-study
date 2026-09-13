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


    //窗口只处理关于：“控件的任务”

    //更新lcdNumber控件的显示
    void handle(int value);

private:
    Ui::Widget *ui;

    //各个模块的对象指针（用来进行信号和槽的绑定）
    Work *work;
    QThread *thread;

};
#endif // WIDGET_H
