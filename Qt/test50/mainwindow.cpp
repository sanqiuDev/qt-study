#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

#include <QPushButton>
#include <QString>

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



void MainWindow::on_pushButton_clicked()
{
    //创建非模态的对话框
    Dialog *dialog  = new Dialog();
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}
