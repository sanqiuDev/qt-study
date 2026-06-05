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
    //给菜单添加一个图标
    menu1->setIcon(QIcon(":\\opt.png"));

    //3.子菜单
    QMenu *menu3 = new QMenu("打开");
    QMenu *menu4 = new QMenu("保存");
    menu1->addMenu(menu3);
    menu1->addMenu(menu4);
    //给子菜单添加一个图标
    menu3->setIcon(QIcon(":\\file.png"));


    //4.菜单项
    QAction *action1 = new QAction("文件1");
    QAction *action2 = new QAction("文件2");
    menu3->addAction(action1);
    menu3->addSeparator();      //在菜单项之间添加分割线
    menu3->addAction(action2);
    //给菜单项添加图标
    action1->setIcon(QIcon(":\\word.png"));
    action2->setIcon(QIcon(":\\ppt.png"));




}

MainWindow::~MainWindow()
{
    delete ui;
}

