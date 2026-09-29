#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test21.h"

class test21 : public QMainWindow
{
    Q_OBJECT

public:
    test21(QWidget *parent = nullptr);
    ~test21();

private:
    Ui::test21Class ui;
};

