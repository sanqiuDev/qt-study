#include "test05.h"
#include <QLabel>

test05::test05(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    //之前我们想要实现：鼠标进入label控件中label的样式就会发生改变，
    //想要实现这样的效果我们是要借助：事件函数的
    //   1. 使用事件过滤器
    //   2. 自定义实现label

    //可以直接写在 QSS 里，**不用写 C++ enterEvent/leaveEvent**就能实现悬浮变色！

    QLabel* label = new QLabel(this);

    label->setGeometry(20, 20, 100, 100);

    label->setStyleSheet(R"(
       QLabel{
            background-color:red;
            font-size:10px;
            border-radius:8px;
            border:solid;
            border-color:blue;
            border-width:3px;
        }
       
       QLabel:hover{
            background-color:#87CEFA;
            color:white;
            border:dashed; 
            border-color:red;     
            border-width:3px;
        }
    )");

    //线型：solid 实线、dashed虚线、dotted点线、none无边框
    //记住先设置线型，在设置颜色
}

test05::~test05()
{}

