#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test4.h"

class test4 : public QMainWindow
{
    Q_OBJECT

public:
    test4(QWidget *parent = nullptr);
    ~test4();

private:
    Ui::test4Class ui;
};

