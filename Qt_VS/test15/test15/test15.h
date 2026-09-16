#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test15.h"

class test15 : public QMainWindow
{
    Q_OBJECT

public:
    test15(QWidget *parent = nullptr);
    ~test15();

private:
    Ui::test15Class ui;
};

