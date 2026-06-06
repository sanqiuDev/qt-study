#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDockWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

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

    //4.为浮动窗口设置标题
    dockWidget->setWindowTitle("这是窗口标题");

    //为浮动窗口中添加一些东西

    //窗口
    QWidget *widget = new QWidget();
    dockWidget->setWidget(widget);

    //布局管理器
    QVBoxLayout *layout = new QVBoxLayout();
    widget->setLayout(layout);

    //标签+按钮
    QLabel *label = new QLabel("标签",this);
    QPushButton *pushButton = new QPushButton("按钮",this);
    layout->addWidget(label);
    layout->addWidget(pushButton);

}

MainWindow::~MainWindow()
{
    delete ui;
}

