#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QInputDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


/*
    QFontDialog::getFont()      → 必须传 &ok
    QInputDialog::getInt()      → 必须传 this + 标题 + 提示
    QInputDialog::getDouble()   → 必须传 this + 标题 + 提示
    QInputDialog::getItem()     → 必须传 this + 标题 + 提示 + 列表
*/

void MainWindow::on_pushButton_int_clicked()
{
    //创建（整数）输入对话框
    int result = QInputDialog::getInt(this,"整数输入对话框","请输入整数");

    qDebug()<<result;
}

void MainWindow::on_pushButton_float_clicked()
{
    //创建（浮点数）输入对话框
    double result = QInputDialog::getDouble(this,"浮点数输入对话框","请输入浮点数");
    qDebug()<<result;
}

void MainWindow::on_pushButton_string_clicked()
{
    //创建（条目）输入对话框
    QStringList item;
    item.push_back("沉舟侧畔千帆过");
    item.push_back("病树前头万木春");

    QString result = QInputDialog::getItem(this,"条目输入对话框","请输入条目",item);
    qDebug()<<result;
}
