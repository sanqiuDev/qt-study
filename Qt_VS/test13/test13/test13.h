#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test13.h"

class test13 : public QMainWindow
{
    Q_OBJECT

public:
    test13(QWidget *parent = nullptr);
    ~test13();

private:
    Ui::test13Class ui;
};

