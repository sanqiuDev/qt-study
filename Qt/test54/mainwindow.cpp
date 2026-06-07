#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColorDialog>
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


void MainWindow::on_pushButton_slow_clicked()
{
    //创建颜色选择对话框（缓慢）
    //1.对话框对象
    QColorDialog *colordialog = new QColorDialog(this);

    //2.设置自动释放
    colordialog->setAttribute(Qt::WA_DeleteOnClose);
    /* parent=this 和 messageBox->setAttribute(Qt::WA_DeleteOnClose);的区别？
      这是一个非常关键的误解：
          父对象（this）管的是 “父窗口销毁时，子窗口才销毁”；
          而 WA_DeleteOnClose 管的是 “用户一点关闭，就立刻销毁对象”，两者完全不是一回事。
    */

    //3.模态调用
    colordialog->exec();
}

void MainWindow::on_pushButton_fast_clicked()
{
    //创建颜色选择对话框（快速）
    QColor color = QColorDialog::getColor(QColor(0,255,0),this,"选择颜色");
    /* getColor(...)：静态函数，直接弹出对话框，让用户选颜色，返回用户选中的 QColor
        第 1 个参数：QColor(0,255,0) ---> 对话框打开时，默认选中的颜色
        第 2 个参数：this ---> 父窗口指针
        第 3 个参数："选择颜色" ---> 对话框窗口的标题栏文字
    */


    //这里补充内容就是将选中颜色设置为窗口背景色
    //方法一：QString + 运算符重载
    QString style = "background-color:rgb("
            + QString::number(color.red())+","
            + QString::number(color.green())+","
            + QString::number(color.blue())
            +");";
    this->setStyleSheet(style);


//    //方法二：char style[]（字符数组） + sprintf
//    char style[1024]={0};
//    sprintf(style,"background-color:rgb(%d,%d,%d)",color.red(),color.green(),color.blue());

//    this->setStyleSheet(style);
}















