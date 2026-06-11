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

public slots:
    void handle(int num);

private:
    Ui::Widget *ui;

    Work *work1;
    Work *work2;
    QThread *thread1;
    QThread *thread2;
};
#endif // WIDGET_H