#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test16.h"

class test16 : public QMainWindow
{
    Q_OBJECT

public:
    test16(QWidget *parent = nullptr);
    ~test16();

private:
    Ui::test16Class ui;
};

