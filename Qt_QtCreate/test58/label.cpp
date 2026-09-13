#include "label.h"

#include <QDebug>
//Label::Label()
//{

//}

//上面的内容是自动生成的，我们要写成
Label::Label(QWidget *parent):QLabel(parent){}
/*
  只要你的自定义控件要在 .ui 文件中使用，就必须提供 类名(QWidget *parent = nullptr) 形式的构造函数，
  这是 Qt 控件的标准约定。即使你自己手动创建控件，也建议保留这个构造，方便设置父窗口和内存管理。


   一句话：因为所有界面控件都继承自 QWidget，而 Qt 靠 parent 指针做三件大事：内存自动管理、界面层级、事件传递。
*/



void Label::enterEvent(QEvent *event)
{
    (void)event;
    qDebug()<<"enterEvent";
}

void Label::leaveEvent(QEvent *event)
{
    (void)event;
    qDebug()<<"leaveEvent";
}

/*
    它们是 QWidget 的两个虚函数，用来捕获 “鼠标进入控件” 和 “鼠标离开控件” 的事件，做悬停效果用的。
        enterEvent：鼠标进入控件区域时，Qt 自动调用
        leaveEvent：鼠标离开控件区域时，Qt 自动调用

    // 鼠标进入
    virtual void enterEvent(QEnterEvent *event);
    // 鼠标离开
    virtual void leaveEvent(QEvent *event);
*/

/*
            QObject
               ↑
            QWidget
           /        \
      QMainWindow   QDialog

           QEvent（独立，不沾上面这条链）
*/
