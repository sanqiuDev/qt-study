#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test02.h"

class test02 : public QMainWindow
{
    Q_OBJECT

public:
    test02(QWidget *parent = nullptr);
    ~test02();

private:
    Ui::test02Class ui;
};

