#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test08.h"

class test08 : public QMainWindow
{
    Q_OBJECT

public:
    test08(QWidget *parent = nullptr);
    ~test08();


    //这里我们来展示一个新的事件：paintEvent
protected:
    void paintEvent(QPaintEvent* event)override;

private:
    Ui::test08Class ui;
};

