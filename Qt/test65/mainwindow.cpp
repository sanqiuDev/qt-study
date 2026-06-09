#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenuBar>
#include <QPlainTextEdit>
#include <QDebug>

#include <fstream>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //快速将菜单的那三个东西创建出来

    //1.搞定菜单栏
//    QMenuBar *menuBar = new QMenuBar();
    QMenuBar *menubar = this->menuBar();

    //2.搞定菜单
    QMenu *menu = new QMenu("文件");
    menubar->addMenu(menu);

    //3.搞定菜单项
    QAction *action1 = new QAction("打开");
    QAction *action2 = new QAction("保存");
    menu->addAction(action1);
    menu->addAction(action2);


    /*
        MainWindow（你）
           ↓
        menuBar（菜单栏，属于 MainWindow）
           ↓
        menu（文件菜单，属于 menuBar）
           ↓
        action（打开/保存，属于 menu）

      关键规则：只要你把一个控件 add 到另一个控件里，Qt 会自动修改父对象！
    */

    //4.将菜单栏设置到窗口上
    this->setMenuBar(menubar);


    //---------------------------------------------------------------
    connect(action1,&QAction::triggered,this,&MainWindow::openFile);
    connect(action2,&QAction::triggered,this,&MainWindow::SaveFile);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::openFile()
{
    //1.获取想要打开的文件的路径
    QString  str = QFileDialog::getOpenFileName(this);
    std::string filePath = str.toStdString();

    //2.以只读的方式打开文件
    std::ifstream in(filePath,std::ios::in);
    if(!in.is_open())
    {
        qDebug()<<"文件打开失败";
        return;
    }

    //3.逐行读取文件中的内容
    std::string buffer,content;
    while(std::getline(in,buffer))
    {
        content += buffer;
    }

    //转换
    QString text = QString::fromStdString(content);

    //4.关闭文件
    in.close();

    //5.将内容展示到QPlainTextEdit中
    ui->plainTextEdit->setPlainText(text);
}


void MainWindow::SaveFile()
{
    //1.获取想要保存的文件路径
    QString str = QFileDialog::getSaveFileName(this);
    std::string filePath = str.toStdString();

    //2.以只写方式打开文件
    std::ofstream out(filePath);
    if(!out.is_open())
    {
        qDebug()<<"文件打开失败";
        return;
    }
    /*
        不是 “没指定写入方式”，而是 std::ofstream 天生就默认是 “只写 + 覆盖” 模式，不用你再写。
        1. std::ofstream 的默认打开模式（C++ 标准规定）
        std::ofstream out(filePath);
        等价于：std::ofstream out(filePath, std::ios::out | std::ios::trunc);
            ios::out：代表写入模式（你要的 “只写”）
            ios::trunc：如果文件已存在，直接清空原内容；不存在则新建
    */

    /* C++ 文件流打开模式（全部 6 种）
        打开模式         含义              说明
        ios::in	      读方式打开	         只能读取文件内容（ifstream 默认）
        ios::out	  写方式打开	         只能写入文件（ofstream 默认）
        ios::app	  追加模式	         写入时从文件末尾开始写，不清空原有内容
        ios::trunc	  清空模式            打开文件时清空原有内容（out 默认带 trunc）
        ios::ate	  打开后跳到文件尾	     但可以移动指针，随便写
        ios::binary	  二进制模式	         不处理换行符，用于 图片/视频/压缩包
    */
    
    //3.获取写入内容并写入文件
    QString content = ui->plainTextEdit->toPlainText();
    std::string text = content.toStdString();
    out<<text;
    
    //5.关闭文件
    out.close();
}















