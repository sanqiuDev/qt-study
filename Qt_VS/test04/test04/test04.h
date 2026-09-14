#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test04.h"

class test04 : public QMainWindow
{
    Q_OBJECT

public:
    test04(QWidget *parent = nullptr);
    ~test04();

private:
    Ui::test04Class ui;
};

