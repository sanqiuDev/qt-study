#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test17.h"

class test17 : public QMainWindow
{
    Q_OBJECT

public:
    test17(QWidget *parent = nullptr);
    ~test17();

private:
    Ui::test17Class ui;
};

