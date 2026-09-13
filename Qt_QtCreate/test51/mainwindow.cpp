#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QMessageBox>
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
    //创建消息对话框（缓慢）

    //1.创建QMessageBox对象
    QMessageBox *messageBox = new QMessageBox(this);

    //2.设置自动释放
    messageBox->setAttribute(Qt::WA_DeleteOnClose);

    //其他
    messageBox->setWindowTitle("消息对话框的标题");
    messageBox->setText("消息对话框的内容");
    messageBox->setIcon(QMessageBox::Warning);
    messageBox->setStandardButtons(QMessageBox::Ok|QMessageBox::Save|QMessageBox::Cancel);

    //3.模态弹出
    messageBox->exec();
}


void MainWindow::on_pushButton_fast_clicked()
{
    //创建消息对话框（快速）

    /*
       QMessageBox 静态接口完整解析（QMessageBox::warning）

    四个入参顺序（固定）
        this：父窗口指针，弹窗依附主窗口，跟随父窗口置顶、模态锁定父界面；
        "对话框标题"：弹窗左上角窗口标题；
        "对话框文本"：弹窗中间展示正文内容；
        QMessageBox::Ok | QMessageBox::Cancel：或运算符|拼接按钮，窗口生成【确定】+【取消】两个按钮。

    同类静态函数（换图标，用法参数完全一致）
        QMessageBox::information()：信息图标（蓝色 i）
        QMessageBox::critical()：错误图标（红色叉）
        QMessageBox::question()：问号询问图标

    返回值 result（int 本质是枚举）点击不同按钮返回对应枚举常量：
        点Ok → result == QMessageBox::Ok
        点Cancel → result == QMessageBox::Cancel

    */

    int result = QMessageBox::warning(this,"消息对话框的标题","消息对话框的内容",QMessageBox::Ok|QMessageBox::Cancel);
    if(result==QMessageBox::Ok)
    {
        qDebug()<<"Ok";
    }
    else
    {
        qDebug()<<"Cancel";
    }


}






