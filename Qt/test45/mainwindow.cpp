#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QToolBar>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //1.添加工具栏
    //第一步：创建工具栏对象
    QToolBar *toolBar = new QToolBar(this);
    //第二步：将工具栏添加窗口上
    this->addToolBar(toolBar);

    //2.添加工具项
    //第一步：创建工具项
    QAction *action1 = new QAction(this);
    QAction *action2 = new QAction(this);
    //第二步：将工具项添加到工具栏中
    toolBar->addAction(action1);
    toolBar->addAction(action2);

    //为工具项添加图标
    action1->setIcon(QIcon(":\\file.png"));
    action2->setIcon(QIcon(":\\tool.png"));

    //简单为操作绑定槽函数看看效果
    connect(action1,&QAction::triggered,this,&MainWindow::handle1);
    connect(action2,&QAction::triggered,this,&MainWindow::handle2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handle1()
{
    qDebug()<<"文件夹";
}

void MainWindow::handle2()
{
    qDebug()<<"小扳手";
}







