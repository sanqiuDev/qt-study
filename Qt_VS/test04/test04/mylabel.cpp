#include "mylabel.h"

//源文件中就是实现头文件中类中声名的函数

//1.构造函数
mylabel::mylabel(QWidget* parent) :QLabel(parent)
{
	//记住在自定义控件的构造函数中可以随意设置改控件

	this->setText("鼠标未进入mylabel中");
	this->setStyleSheet(R"(QLabel{
		 background-color:red;
		color:blue;
   })");
}

void mylabel::enterEvent(QEnterEvent* event)
{
	this->setText("鼠标进入mylabel中了");
	this->setStyleSheet(R"(QLabel{
		 background-color:blue;
		color:red;
   })");

	QLabel::enterEvent(event);
}


void mylabel::leaveEvent(QEvent * event)
{
	this->setText("鼠标未进入mylabel中");
	this->setStyleSheet(R"(QLabel{
		 background-color:red;
		color:blue;
   })");

	QLabel::leaveEvent(event);
}

