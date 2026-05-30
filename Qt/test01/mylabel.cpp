#include "mylabel.h"

#include <iostream>
#include <QDebug>

MyLabel::MyLabel(QWidget *parent):QLabel(parent)
{

}

MyLabel::~MyLabel()
{
    qDebug()<<"MyLabel，被销毁";
    qDebug()<<"MyLabel，被销毁\n";
    qDebug()<<"MyLabel，被销毁\n"<<Qt::endl;
}

/*

🔍 错误原因
    qDebug() 是 Qt 的日志输出函数，它的工作方式和 std::cout 不一样：
        std::endl 不仅会输出换行，还会强制刷新缓冲区，它是 std 标准库的函数。
        qDebug() 有自己的换行和刷新机制，直接用 << std::endl 会导致编译器找不到匹配的重载函数
✅ 两种修复方案（推荐第一种）
方案一：直接去掉 std::endl（推荐）
    Qt 的 qDebug() 会在输出结束后自动换行，不需要额外加 std::endl：
    MyLabel::~MyLabel()
    {
        qDebug() << "MyLabel，被销毁";
    }

方案二：改用 Qt 风格的换行
    如果你想显式控制换行，可以用 Qt::endl 或者直接加 \n：

    // 方式1：用 Qt::endl
    qDebug() << "MyLabel，被销毁" << Qt::endl;

    // 方式2：用 \n 转义字符
    qDebug() << "MyLabel，被销毁\n";

*/
