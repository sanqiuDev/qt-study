#include "test02.h"
#include <QLabel>

test02::test02(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

/*    //创建标签并给它创建一个初始样式
     QLabel* label = new QLabel(this);*/


    label->setText("原始文本");
    label->resize(100, 100);
    //label->setGeometry(10, 10); x，y，宽，高（行，列，行，列）
    label->move(0, 0);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("background-color:#1767e2;font-size:7px");
    //

}

test02::~test02()
{}

//`test02` 是 **QMainWindow（主窗口）**，你重写的 `enterEvent` 是**主窗口的鼠标进入事件**，**不是 QLabel label 的**。
//所以现在的效果其实是鼠标进入主窗口后，主窗口上的label控件形式发生变化
void test02::enterEvent(QEnterEvent * event)
{
    //第一步：这里面我们修改一些内容
    label->setText("鼠标光标进入到了label中了");

    label->resize(150, 50);
    label->move(150, 150);
    label->setStyleSheet("background-color:red;font-size:10px");
    

    //第二步：父控件调用事件
    QMainWindow::enterEvent(event);
    
}

void test02::leaveEvent(QEvent * event)
{

    label->setText("原始文本");
    label->resize(100, 100);
    //label->setGeometry(10, 10); x，y，h，w
    label->move(0, 0);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("background-color:#1767e2;font-size:7px");

    QMainWindow::leaveEvent(event);
     /*
        为什么重写 Qt 事件函数要调用基类实现
            这是 Qt 事件分发的一个通用约定，不只是 leaveEvent，mousePressEvent、paintEvent、resizeEvent 等都一样。
        基类 QWidget::leaveEvent 在干什么
        虽然你看到的源码里它"什么都没做"，但它承担隐性的状态维护，包括但不限于：
           1. 更新鼠标 hover/离开状态标记 —— Qt 内部用一组标志位跟踪"鼠标当前是否悬停在某控件上"，这些状态会影响后续事件分发
           2. 更新 mouse grabber（鼠标捕获者）链 —— 如果之前 grabMouse() 过的窗口被 leave，需要修正
           3. 触发无障碍（Accessibility）通知 —— 屏幕阅读器依赖这个事件通知"焦点对象变了"
           4. 清理某些脏标记（dirty flag） —— 与样式、子控件更新有关
           4. 向父类链上抛 —— QWidget::leaveEvent 内部可能还会通知 QObject::event 的其他处理路径


           ----------------------------------------------------------------------------------------------------

           重写 QWidget 的事件函数（enterEvent /leaveEvent/mouseMoveEvent /paintEvent 等）：
              如果你只是附加自定义逻辑，不想完全覆盖原生行为，函数末尾调用 父类::事件名(event)
             如果你要完全接管这个事件，阻止 Qt 默认处理，就不要调用父类函数
           举个例子：重写`mousePressEvent`，如果你想**拦截点击，不让原生处理**，就不调用父类。
     */
}

void test02::mouseMoveEvent(QMouseEvent * event)
{
    QMainWindow::mouseMoveEvent(event);
}

void test02::mousePressEvent(QMouseEvent * event)
{
    QMainWindow::mousePressEvent(event);
}

void test02::mouseReleaseEvent(QMouseEvent * event)
{
    QMainWindow::mouseReleaseEvent(event);
}

