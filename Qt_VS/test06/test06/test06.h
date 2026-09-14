#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test06.h"
#include <QMouseEvent>  //注意要添加头文件

class test06 : public QMainWindow
{
    Q_OBJECT

public:
    test06(QWidget *parent = nullptr);
    ~test06();

    //这次我们来深挖鼠标的另一个事件：mouseMoveEvent   //注意要添加头文件
protected:
    void mouseMoveEvent(QMouseEvent* event)override;

private:
    Ui::test06Class ui;
};

