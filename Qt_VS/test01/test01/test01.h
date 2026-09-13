#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test01.h"

class test01 : public QMainWindow
{
    Q_OBJECT

public:
    test01(QWidget *parent = nullptr);
    ~test01();

private:
    Ui::test01Class ui;
};

