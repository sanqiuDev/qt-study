#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test05.h"

class test05 : public QMainWindow
{
    Q_OBJECT

public:
    test05(QWidget *parent = nullptr);
    ~test05();

private:
    Ui::test05Class ui;
};

