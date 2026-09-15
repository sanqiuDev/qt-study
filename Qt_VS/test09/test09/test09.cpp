#include "test09.h"

#include <QPainter>
#include <QPen>
#include <QBrush>

test09::test09(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    //这里我们来展示一下：画家QPainter 的两个成员函数：save和restore 的使用

}

test09::~test09()
{}

void test09::paintEvent(QPaintEvent * event)
{
    //1.
    QPainter painter(this);
    
    //2.
    QPen pen;
    //pen.setColor(Qt::red);
    //pen.setWidth(2);
    //painter.setPen(pen);
    painter.setPen(QPen(Qt::red, 2));
    painter.drawRect(20, 20, 50, 50);   //画一个矩形

    painter.save();  //把红色保存起来

     
    painter.setPen(QPen(Qt::blue, 5));    //画家换了一只新🖊
    painter.drawEllipse(100, 20, 60, 60);

    painter.restore();
    painter.drawEllipse(200, 20, 80, 60);

    QMainWindow::paintEvent(event);

    /*
        save()：把当前画家所有绘图状态压入栈保存（画笔、画刷、字体、变换矩阵、裁剪区域、透明度等）
        restore()：从栈弹出，恢复到上一次 save 时的状态。
    */

}

