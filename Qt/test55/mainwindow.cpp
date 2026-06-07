#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFileDialog>

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


void MainWindow::on_pushButton_open_one_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this);
    qDebug()<<filePath;
}

void MainWindow::on_pushButton_open_some_clicked()
{
    /* 两个关键函数的区别
                    函数                      功能	          返回值类型
        QFileDialog::getOpenFileName()	   选择单个文件         QString
        QFileDialog::getOpenFileNames()	   支持多选文件         QStringList
     你的代码里用了 getOpenFileNames()，但却用 QString filePath 接收，所以报错。


    */
    QStringList filePaths = QFileDialog::getOpenFileNames(this);
    //qDebug()<<filePaths;
    //这里我们也可以遍历每个文件路径进行输出
     for(auto path:filePaths)
     {
         qDebug()<<path;
     }
}

void MainWindow::on_pushButton_save_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this);
    qDebug()<<filePath;
}
