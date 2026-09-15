#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test09.h"

class test09 : public QMainWindow
{
    Q_OBJECT

public:
    test09(QWidget *parent = nullptr);
    ~test09();

protected:
    void paintEvent(QPaintEvent* event)override;

private:
    Ui::test09Class ui;
};

