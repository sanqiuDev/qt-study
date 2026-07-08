#pragma once

#include <QtWidgets/QWidget>
#include "ui_test01.h"

class test01 : public QWidget
{
    Q_OBJECT

public:
    test01(QWidget *parent = nullptr);
    ~test01();

private:
    Ui::test01Class ui;
};

