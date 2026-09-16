#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test18.h"

class test18 : public QMainWindow
{
    Q_OBJECT

public:
    test18(QWidget *parent = nullptr);
    ~test18();

private:
    Ui::test18Class ui;
};

