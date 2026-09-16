#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test14.h"

class test14 : public QMainWindow
{
    Q_OBJECT

public:
    test14(QWidget *parent = nullptr);
    ~test14();

private:
    Ui::test14Class ui;
};

