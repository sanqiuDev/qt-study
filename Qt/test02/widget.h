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
    void on_pushButton_2_clicked();
    void handle_mySignal();

    void on_pushButton_4_clicked();

    void handle_mySignal2();

signals:
    //首先我们要明白几件事情就是：
    /* 在widget.h文件中Widget类中可以声明：
         1. 构造函数 +  析构函数
         2. 槽函数
         3. 信号
    */
    void  mySignal(); //注意信号函数的特点：1）我们不需要再去widget.cpp文件中实现定义，2）这个函数的返回值一定是void


private:
    Ui::Widget *ui;

    //定义全局按钮控件
//    QPushButton *pushButton;
};
#endif // WIDGET_H
