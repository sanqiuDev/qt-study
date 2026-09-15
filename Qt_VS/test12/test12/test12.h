#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test12.h"


//注意这里要前向生命
class test12Private;

class test12 : public QMainWindow
{
    Q_OBJECT

public:
    test12(QWidget *parent = nullptr);
    ~test12();


    //这里我们来演示PIMPL是怎么使用的

    //先来两个函数
    //1.设置
    void setText(const QString& str);
    //2.获取
    QString text()const;

private:

    //唯一私有成员：指向实现类的指针
    test12Private* d_ptr;


    Ui::test12Class ui;
};

