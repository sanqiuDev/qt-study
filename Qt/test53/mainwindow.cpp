#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //任务：尝试“消息对话框中————自定按钮”的功能
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //创建对话框
    QMessageBox *messageBox = new QMessageBox();
    messageBox->setAttribute(Qt::WA_DeleteOnClose);


    //其他的一些操作
    messageBox->setWindowTitle("消息对话框的标题");
    messageBox->setText("消息对话框的内容");
    messageBox->setIcon(QMessageBox::Warning);
    messageBox->setStandardButtons(QMessageBox::Ok|QMessageBox::Save|QMessageBox::Cancel);

    //自定按钮
    QPushButton *pushButton = new QPushButton("自定义按钮",messageBox);
    //messageBox->addButton(pushButton,QMessageBox::Retry)
    messageBox->addButton(pushButton,QMessageBox::AcceptRole);
    /*
        // 给自定义按钮指定角色（AcceptRole/RejectRole/ActionRole 等）
        messageBox->addButton(pushButton, QMessageBox::AcceptRole);
        // 或
        messageBox->addButton(pushButton, QMessageBox::RejectRole);

        QMessageBox::Retry 是 “按钮类型”，只能用在 setStandardButtons 或 addButton(文字, 标准按钮) 里；
        给自定义 QPushButton 指定角色时，只能用 ButtonRole 枚举（AcceptRole/RejectRole/ActionRole 等）。
    */

    int result = messageBox->exec();


    if(result==QMessageBox::Ok) qDebug()<<"Ok";
    else if(result==QMessageBox::Save) qDebug()<<"Save";
    else if(result==QMessageBox::Cancel) qDebug()<<"Cancel";
}
















