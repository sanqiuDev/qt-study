#pragma once

#include <QLabel>

//实现自定义标签控件 
class mylabel :public QLabel
{
	Q_OBJECT    // Q_OBJECT 是宏，本身展开后已带分号，再加分号会导致 moc 处理失败、编译报错

public:
	explicit mylabel(QWidget* parent = nullptr);
	//~mylabel();

	//接下来定义一些事件函数
protected:
	void enterEvent(QEnterEvent* event)override;
	void leaveEvent(QEvent* event)override;
};