#include "test08.h"

#include <QPainter>
#include <QPen>
#include <QBrush>

test08::test08(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

test08::~test08()
{}

void test08::paintEvent(QPaintEvent * event)
{
    //第一步：创建画家
    QPainter painter(this); //创建画家，绑定当前控件this
    /*
        QPainter painter(this); 确实是栈上局部对象，this 是传给 QPainter 构造函数的绘图设备（QPaintDevice*），不是父对象绑定！
        很多新手会混淆：new QWidget(this) 里的this是父对象；但 QPainter 构造的参数this是绘图设备，完全两码事。

        QPainter 构造函数原型：QPainter(QPaintDevice *device);
        QPaintDevice 是一个抽象基类，QWidget 继承自 QPaintDevice，所以你的 MyLabel（QLabel→QWidget）可以作为绘图设备传入。

        一句话：告诉画家，你要在哪块画布上画画。
    
            QPainter painter(this); 
            // painter：画家
            // this：画布（当前MyLabel控件）

         画家 (painter) 在栈上，画布 (this) 是控件，在堆上。
         painter 只是一个绘图工具，**不是子控件，不存在父子内存管理**！栈上 painter 出作用域自动析构，不会 delete this。
    */


    //第二步：创建画笔
    QPen pen;
    pen.setColor(Qt::blue);
    pen.setWidth(2);
    painter.setPen(pen);

    //第三步：创建画刷
    QBrush brush;
    brush.setColor(QColor(200, 230, 255));
    brush.setStyle(Qt::SolidPattern); //实心填充
    painter.setBrush(brush);

    //这里可以稍微注意一下颜色的设置
    /*
        QColor(255,0,0);          //rgb 0~255
        QColor("#ff0000");        //十六进制，和QSS写法一样
        Qt::red;                  //预定义常量
    */


    //1.绘制图形
    painter.drawRect(20, 20, 100, 80);   //矩形
    painter.drawEllipse(150, 20, 80, 80); //椭圆  （正方形就是圆形）
    painter.drawLine(20, 120, 200, 120);  //直线   (起点(x1,y1)终点(x2,y2))

    //2.绘制文字
    painter.drawText(20, 160, "Hello paintEvent!");


    //3.绘制图案
    QPixmap pix(":/xiaoxiong.jpg");
    painter.drawPixmap(300, 20, 100, 100, pix);


    // 调用基类的paintEvent，保留QMainWindow原本的文字绘制！
    QMainWindow::paintEvent(event);
}

