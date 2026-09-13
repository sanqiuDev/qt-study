#include "widget.h"
#include "ui_widget.h"


#include <QWheelEvent>
#include <QDebug>
#include <QKeyEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}


//重写：“滚轮的滚动事件”的虚函数
/* 注意；
      QMouseEvent：处理“鼠标事件”
      QWheelEvent：处理“滚轮事件”
*/
void Widget::wheelEvent(QWheelEvent *event)
{
//    int total += event->delta(); += 不能用在变量声明上。
    total += event->delta();
    qDebug()<<"滚轮移动的距离是："<<total<<Qt::endl;
}


//重写：“键盘的按键事件”的虚函数
void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_A&&event->modifiers()==Qt::ControlModifier)
    {
        qDebug()<<"键盘按下了ctrl+a键"; //只有用户同时按下：“ctrl”+“a” 键才会打印
    }

    /*
        event->modifiers()：获取按下的修饰键
        event->modifiers()：返回修饰键的状态，比如 Ctrl、Shift、Alt 键
          常见的修饰键枚举：
            Qt::ControlModifier：Ctrl 键
            Qt::ShiftModifier：Shift 键
            Qt::AltModifier：Alt 键
    */
}
