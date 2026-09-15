#pragma once



#include <QtWidgets/QMainWindow>
#include "ui_test10.h"

class test10 : public QMainWindow
{
    Q_OBJECT

public:
    test10(QWidget *parent = nullptr);
    ~test10();

    //之前我们看到了绘制普通文字，现在我们来学习如何绘制富文本？
protected:
    void paintEvent(QPaintEvent* event)override;

private:
    Ui::test10Class ui;
};

