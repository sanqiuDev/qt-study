#include "test01.h"

test01::test01(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    //这里我们修改鼠标的图标
	//setCursor(Qt::PointingHandCursor);  //界面上鼠标的图标是:“小手的样式”
    setCursor(QCursor(Qt::PointingHandCursor));

	setCursor(Qt::ArrowCursor);           //界面上鼠标的图标是:“箭头的样式”
	setCursor(QCursor(Qt::CrossCursor));  //界面上鼠标的图标是:“十字的样式”
    /*
        setCursor(Qt::PointingHandCursor); 和 setCursor(QCursor(Qt::PointingHandCursor));都合法，
       根源是 C++ 隐式类型转换 + QCursor 的单参数构造函数标记不是 explicit
    */

    
}

test01::~test01()
{}

