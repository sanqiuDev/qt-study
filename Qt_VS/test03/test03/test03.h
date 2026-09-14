#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test03.h"

class test03 : public QMainWindow
{
    Q_OBJECT

public:
    test03(QWidget *parent = nullptr);
    ~test03();

     
protected:
/*    void enterEvent(QEnterEvent* event) override;
    void leaveEvent(QEvent* event)override;*/
    
    //这次我们使用事件过滤器
    bool eventFilter(QObject* obj, QEvent* event) override;
        
private:
    Ui::test03Class ui;

    QLabel* label;
};

