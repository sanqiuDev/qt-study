#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test07.h"

class test07 : public QMainWindow
{
    Q_OBJECT

public:
    test07(QWidget *parent = nullptr);
    ~test07();

private:
    Ui::test07Class ui;
};

