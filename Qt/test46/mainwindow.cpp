#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //1.创建工具栏
    QToolBar *toolBar1 = new QToolBar(this);
    QToolBar *toolBar2 = new QToolBar(this);
    QToolBar *toolBar3 = new QToolBar(this);
    QToolBar *toolBar4 = new QToolBar(this);

    //更改工具栏的一些属性
    //（1）设置停靠位置（默认）
    this->addToolBar(Qt::LeftToolBarArea,toolBar1);
    this->addToolBar(Qt::RightToolBarArea,toolBar2);
    this->addToolBar(Qt::TopToolBarArea,toolBar3);
    this->addToolBar(Qt::BottomToolBarArea,toolBar4);


    //（2）限制可停靠范围
    toolBar1->setAllowedAreas(Qt::LeftToolBarArea);

    //（3）设置浮动状态
    toolBar2->setFloatable(false);

    //（4）设置移动状态
    toolBar3->setMovable(false);

    //2.创建工具项
    QAction *action1 = new QAction("动作1");
    QAction *action2 = new QAction("动作2");
    QAction *action3 = new QAction("动作3");
    QAction *action4 = new QAction("动作4");

    toolBar1->addAction(action1);
    toolBar2->addAction(action2);
    toolBar3->addAction(action3);
    toolBar4->addAction(action4);
}

MainWindow::~MainWindow()
{
    delete ui;
}

