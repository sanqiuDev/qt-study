//#ifndef WIDGET_H
//#define WIDGET_H

//#include <QWidget>

//QT_BEGIN_NAMESPACE
//namespace Ui { class Widget; }
//QT_END_NAMESPACE

//class Widget : public QWidget
//{
//    Q_OBJECT

//public:
//    Widget(QWidget *parent = nullptr);
//    ~Widget();

//private:
//    Ui::Widget *ui;
//};
//#endif // WIDGET_H

//第一步：添加头文件保护宏
#ifndef WIDGET_H
#define WIDGET_H

//第二步：定义头文件
#include <QWidget>


#include <QPushButton>

//第三步：定义命名空间
QT_BEGIN_NAMESPACE
namespace Ui {class Widget;}
QT_END_NAMESPACE

//第四步：公有继承QWidget类创建类Widget
class Widget:public QWidget
{
    //内部的第一部分：Qt核心宏
    Q_OBJECT //细节就是它的后面没有分号

public:
    //内部的第二部分：构造和析构函数
    Widget(QWidget* parent =nullptr);
    ~Widget();


    //头文件用来声明函数这里我们可以来声明一个‘信号处理函数’
    void handleClick();
    void handleClick1();

private:
    //内部的第三部分：UI的对象指针
    Ui::Widget *ui;


    //这里除了初始的时候定义一个UI对象指针之外还可以定义：
    //你在widget.cpp文件中的构造函数中定义的一切控件
    //定义在这里和定义在那里和定义在这里的区别就是：
    //定义在这里是 “全局”
    QPushButton *pushButton2;
};

#endif





























