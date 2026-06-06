#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QProgressBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //1.添加状态栏
    //第一步：创建状态栏
    QStatusBar *statusbar = this->statusBar();
    //第二步：将状态栏添加到窗口
    this->setStatusBar(statusbar);


    //2.显示实时消息
    statusbar->showMessage("实时消息",2000);


    //3.显示永久消息
    //第一步：创建标签
    QLabel *label1 = new QLabel("永久消息1",this);
    //第二步：手动清除实时消息
    statusbar->clearMessage();
    //第三步：将标签添加进状态栏中（默认：左下角）
    statusbar->addWidget(label1);



    //第一步：创建标签
    QLabel *label2 = new QLabel("永久消息2",this);
    //第二步：调整消息位置（右下角）
    statusbar->addPermanentWidget(label2);




    //4.显示进度信息
    //第一步：创建进度条
    QProgressBar *progressBar = new QProgressBar();
    //第二步：将进度条添加到状态栏中
    statusbar->addWidget(progressBar);

    //简单的设置一下初始值
    progressBar->setValue(50);
}

MainWindow::~MainWindow()
{
    delete ui;
}

