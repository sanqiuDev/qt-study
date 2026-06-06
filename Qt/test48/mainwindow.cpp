#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDockWidget>
#include <QListWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //1.创建浮动窗口
    QDockWidget *dockWidget = new QDockWidget("浮动窗口",this);

    //2.为浮动窗口添加列表
    QListWidget *listWidget = new QListWidget();
    dockWidget->setWidget(listWidget);
    //为列表添加一些内容
    listWidget->addItem("功能1");
    listWidget->addItem("功能2");

    //3.设置浮动窗口默认的停靠位置
    this->addDockWidget(Qt::BottomDockWidgetArea,dockWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}

