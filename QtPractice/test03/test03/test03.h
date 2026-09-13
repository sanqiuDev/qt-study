#pragma once

#include <QtWidgets/QWidget>
#include "ui_test03.h"

class test03 : public QWidget
{
    Q_OBJECT

public:
    test03(QWidget *parent = nullptr);
    ~test03();

private:
    Ui::test03Class ui;
};

