#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void handle_title(const QString &text);

 signals:
    void mySignal(const QString);
    /* 这里我小小的总结一下就是：
        当我定义一个：槽函数的时候 ---> 任务就是：在widget.cpp文件中实现定义
        当我定义一个：信号函数的时候 --> 任务就是：使用connect绑定这个信号 + 实现处理这个信号的槽函数的声明和定义
    */

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
