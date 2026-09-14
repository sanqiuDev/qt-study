#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test02.h"

#include <QLabel>

class test02 : public QMainWindow
{
    Q_OBJECT

public:
    test02(QWidget *parent = nullptr);
    ~test02();

private:
    Ui::test02Class ui;
    QLabel* label = new QLabel(this);


    //关于事件这个语法一次掌握（针对“鼠标”）
    /*
        1. 第一步：头文件中声明事件函数
        2. 第二步：源文件中实现这些事件函数
    
    */
protected:
    //第一组：进入、离开
    void enterEvent(QEnterEvent *event)override;  
    void leaveEvent(QEvent *event)override;


    //第二组：移动、按下、释放
    void mouseMoveEvent(QMouseEvent *event)override;
    void mousePressEvent(QMouseEvent *event)override;
    void mouseReleaseEvent(QMouseEvent *event)override;

    /*
        对与鼠标的事件的函数的我们需要格外注意下面几个的事情：

            1. 事件函数是需要进行重写的所以我们需要给它们 override
            2. 返回值是void
            3. enterEvent 和 leaveEvent 这两个函数名和其他一组区别，一个它们两个参数的区别
    */
};

