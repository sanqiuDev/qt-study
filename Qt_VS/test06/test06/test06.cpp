#include "test06.h"
#include <QLabel>
#include <QDebug>


test06::test06(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QLabel* label = new QLabel(this);
    label->setGeometry(20, 20, 300, 300);

    label->setStyleSheet("background-color:red");
    //label->setStyleSheet(R"(
    //    QLabel
    //    {
    //        background-color:blue;

    //    }
    //    
    //    QLabel:hover
    //    {
    //        background-color:red;
    //    }
    //)");


    //这次我们也不自定义标签了，就直接在主界面中实验“鼠标的移动事件”

    // 开启鼠标跟踪：不按鼠标也能收到mouseMoveEvent
    this->setMouseTracking(true);
    //结论：如果没有这句话，必须按着鼠标+鼠标移动，qDebug才会输出x，y坐标值

    /*
     为什么 setMouseTracking 完全没反应？
       窗口的实际分层是：
          QMainWindow (this)          ← setMouseTracking(true) ✓
          └─ centralWidget           ← setMouseTracking(false) ✗  占了几乎全部客户区
       
      事件分发流程（鼠标不按键、客户区里移动）：
            1. 鼠标位置 (x, y) → Qt 判断出目标 widget 是 centralWidget
            2. centralWidget 没有开追踪 → 直接丢弃该事件
            3. 事件永远不会到达 MainWindow
        这就是核心误区：setMouseTracking(true) 不是"递归开启所有祖先的追踪"。
        它只让 this 本身在作为事件目标时能收到 mouseMoveEvent。而 MainWindow 自己几乎没有裸露区域（都被 centralWidget 占了），所以等于白开。
        唯一一行就能验证
        把鼠标移到 菜单栏 / 工具栏 / 状态栏 那些区域上，不点击你会看到坐标照常输出 — 因为那些区域不是 centralWidget 管的，MainWindow 自己就是目标 widget。
    
    */

    ui.centralWidget->setMouseTracking(true);  //注意：针对QMainWindow它也需要开始追踪
    /*
        只有 QMainWindow 才有 centralWidget，QWidget、QDialog 没有这个东西

        1. 一句话解释

        QMainWindow 是带框架的窗口：自带标题栏、最小化 / 最大化 / 关闭按钮、菜单栏、工具栏、状态栏
        但是 QMainWindow 本身不能直接放子控件（QLabel、按钮等）
        它预留了一块空白区域，这块区域就叫 centralWidget（中心部件），所有你自己写的控件，都要放在 centralWidget 上面

        QMainWindow窗口
        ┌─────────────────────────────┐
        │ 菜单栏 / 工具栏              │
        ├─────────────────────────────┤
        │ 【centralWidget 中心区域】   │ ← 你放label、按钮的地方
        │                             │
        ├─────────────────────────────┤
        │ 状态栏                       │
        └─────────────────────────────┘
     */

    label->setMouseTracking(true);  //label需要不点击的话，也需要这样
}

test06::~test06()
{}

void test06::mouseMoveEvent(QMouseEvent *event)
{
    QPoint point = event->pos();
    /* 注意定义头文件：
        编译器只看到了 QMouseEvent 的前向声明（通常由 <QtWidgets/QMainWindow> 或 <QWidget> 间接带进来），
        但没有看到完整的类定义。前向声明只能用于指针/引用作为参数类型出现在声明中，
        不能在 .cpp 文件中实际解引用（例如调用 event->pos()、event->button()）。
    */
    qDebug() << "相对坐标：x：" << point.x() << "y：" << point.y();

    QMainWindow::mouseMoveEvent(event);
}


