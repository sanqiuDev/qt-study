#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test19.h"

class test19 : public QMainWindow
{
    Q_OBJECT

public:
    test19(QWidget *parent = nullptr);
    ~test19();

private:
    Ui::test19Class ui;
};

