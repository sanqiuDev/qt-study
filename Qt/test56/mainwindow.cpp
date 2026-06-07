#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFontDialog>
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


void MainWindow::on_pushButton_slow_clicked()
{
    //创建字体选择对话框（缓慢）
    QFontDialog *fontDialog = new QFontDialog(this);
    fontDialog->setAttribute(Qt::WA_DeleteOnClose);
    fontDialog->exec();

}

void MainWindow::on_pushButton_fast_clicked()
{
    bool ok;
    //创建字体选择对话框（快速）
    QFont font = QFontDialog::getFont(&ok);
    /*
        ✅ QColorDialog::getColor()：参数全默认，可以空参调用
        ❌ QFontDialog::getFont()：第一个参数 bool *ok 没有默认值，必须传（【独有】确认标记）
    */
    qDebug()<<"ok="<<ok;
}

















