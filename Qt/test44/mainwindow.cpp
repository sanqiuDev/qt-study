#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //1.菜单栏
    QMenuBar *menubar = this->menuBar();
    this->setMenuBar(menubar);

    //2.菜单
    QMenu *menu1 = new QMenu("文件");
    QMenu *menu2 = new QMenu("编辑");
    menubar->addMenu(menu1);
    menubar->addMenu(menu2);

    //3.子菜单
    QMenu *menu3 = new QMenu("打开");
    QMenu *menu4 = new QMenu("保存");
    menu1->addMenu(menu3);
    menu1->addMenu(menu4);


    //4.菜单项
    QAction *action1 = new QAction("文件1");
    QAction *action2 = new QAction("文件2");
    menu3->addAction(action1);
    menu3->addAction(action2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

