#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //1.创建菜单栏
    //第一步：创建菜单栏对象
    QMenuBar *menubar = this->menuBar(); //注意细节：这里没有new
    //第二步：将对象添加到窗口上
    this->setMenuBar(menubar);
    /*
        this->menuBar()
            如果窗口之前没有菜单栏：Qt 在主窗口内部自动new QMenuBar，挂载到主窗口对象树，返回指针；
            如果已有菜单栏：直接返回已有菜单栏地址，不会重复创建。

        new QMenuBar()是手动新建，三个坑
            替换原有菜单栏：主窗口原本内置菜单栏被抛弃，脱离对象树，频繁创建窗口会造成内存泄漏；
            多此一举：主窗口原生自带菜单栏空间，额外堆创建浪费资源；
            普通 QWidget 必须 new：只有 QMainWindow 能用 menuBar ()，普通 QWidget 没有这个函数，只能手动 new 菜单栏 + 塞进布局。
    */


    //2.添加菜单
    //第一步：创建菜单
    QMenu *menu1 = new QMenu("文件");
    QMenu *menu2 = new QMenu("编辑");
    QMenu *menu3 = new QMenu("构建");

    //第二步：将菜单添加到菜单栏上
    menubar->addMenu(menu1);
    menubar->addMenu(menu2);
    menubar->addMenu(menu3);

    //3.添加菜单项
    //第一步：创建菜单项
    QAction *action1 = new QAction("打开");
    QAction *action2 = new QAction("保存");
    QAction *action3 = new QAction("关闭");

    //第二步：将菜单项添加到菜单中
    menu1->addAction(action1);
    menu1->addAction(action2);
    menu1->addAction(action3);


    //补充：信号和槽的交互内容
    connect(action3,&QAction::triggered,this,&MainWindow::close);
    connect(action2,&QAction::triggered,this,&MainWindow::handle);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handle()
{
    qDebug()<<"内容已经保存"<<Qt::endl;
}


