#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   //任务：给窗口设置快捷键

    //1.创建出菜单栏
    QMenuBar *menubar = this->menuBar();
    this->setMenuBar(menubar);

    //2.创建出菜单
    QMenu *menu1 = new QMenu("文件(&F)");
    QMenu *menu2 = new QMenu("编辑(&E)");
    menubar->addMenu(menu1);
    menubar->addMenu(menu2);

    //3.创建菜单项
    QAction *action1 = new QAction("保存(&S)");
    QAction *action2 = new QAction("关闭(&C)");
    menu1->addAction(action1);
    menu1->addAction(action2);


    //绑定槽函数
    connect(action1,&QAction::triggered,this,&MainWindow::handle);
    connect(action2,&QAction::triggered,this,&MainWindow::close);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handle()
{
    qDebug()<<"内容已经保存成功"<<Qt::endl;
}
