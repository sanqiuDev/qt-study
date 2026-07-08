#pragma once

#include <QtWidgets/QWidget>
#include "ui_test02.h"

class test02 : public QWidget
{
    Q_OBJECT

public:
    test02(QWidget *parent = nullptr);
    ~test02();

private:
    Ui::test02Class ui;
};

