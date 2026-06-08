#include "label.h"

//

//Label::Label()
//{

//}

Label::Label(QWidget *parent):QLabel(parent)
{
//    // 开启鼠标追踪 → 不用按也能实时捕获移动事件
//    this->setMouseTracking(true);
}


//重写“鼠标点击事件”的虚函数
void Label::mousePressEvent(QMouseEvent *ev)
/*
    Label::：说明这个函数是自定义的 Label 类的成员函数
    mousePressEvent：是 QLabel 基类里的虚函数，重写它就能捕获鼠标按下事件
    QMouseEvent *event：这是 Qt 传进来的鼠标事件对象，里面包含了 “哪个键被按了、按在哪个位置” 等信息
*/
{
    if(ev->button()==Qt::LeftButton)
    {
        qDebug()<<"点击了鼠标左键";
    }
    else if(ev->button()==Qt::MiddleButton)
    {
        qDebug()<<"点击了鼠标的中键";
    }
    else if(ev->button()==Qt::RightButton)
    {
        qDebug()<<"点击了鼠标的右键";
    }

    qDebug()<<"当前鼠标点击的位置是：";
    qDebug()<<"相对于Label控件左上角："<<ev->x()<<","<<ev->y();
    qDebug()<<"相对于widge窗口左上角："<<ev->globalX()<<","<<ev->globalY();
}

//重写“鼠标释放事件”的虚函数
void Label::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button()==Qt::LeftButton)
    {
        qDebug()<<"释放了鼠标左键";
    }
    else if(ev->button()==Qt::MiddleButton)
    {
        qDebug()<<"释放了鼠标的中键";
    }
    else if(ev->button()==Qt::RightButton)
    {
        qDebug()<<"释放了鼠标的右键";
    }
}

//重写“鼠标双击事件”的xu'函数
void Label::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        qDebug()<<"双击了鼠标左键";
    }
    else if(event->button()==Qt::MiddleButton)
    {
        qDebug()<<"双击了鼠标中键";
    }
    else if(event->button()==Qt::RightButton)
    {
        qDebug()<<"双击了鼠标右键";
    }
}

//重写“鼠标移动事件”的虚函数
void Label::mouseMoveEvent(QMouseEvent *ev)
{
    qDebug()<<"当前鼠标的位置："
            <<ev->x()<<","<<ev->y();
}










