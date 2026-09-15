#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test11.h"

class test11 : public QMainWindow
{
    Q_OBJECT

public:
    test11(QWidget *parent = nullptr);
    ~test11();

protected:
    void paintEvent(QPaintEvent* event)override;

private:
    Ui::test11Class ui;
};

