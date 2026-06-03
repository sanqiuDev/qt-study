#include "widget.h"
#include "ui_widget.h"

#include <QLabel>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QLabel *label = new QLabel(this);
    //1.获取TextEdit控件中内容
    const QString str = ui->textEdit->toPlainText();
    label->setText(str);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_textEdit_textChanged()
{
    qDebug()<<"textChanged信号触发了："
            <<ui->textEdit->toPlainText()
           <<Qt::endl;
}

void Widget::on_textEdit_selectionChanged()
{
    qDebug()<<"selectionChanged信号触发了："
            <<ui->textEdit->toPlainText()
           <<Qt::endl;
}
/*
   这里我简单的介绍一下：textChanged 和 selectionChanged 这两个信号的区别是什么
      一句话说明：在TextEdit控件中
         1. 使用键盘触发：textChanged 信号
         2. 使用鼠标触发：selectionChanged 信号
*/

// cursorPositionChanged信号不同于上面两个信号的区别是：这个信号是不管你是你的鼠标还是你的键盘动都会触发
void Widget::on_textEdit_cursorPositionChanged()
{
    qDebug()<<"cursorPositionChanged信号触发了："
            <<ui->textEdit->toPlainText()
           <<Qt::endl;
}




void Widget::on_textEdit_undoAvailable(bool b)
{
    qDebug()<<"undoAvailable：撤销功能可用"<<b<<Qt::endl;
}


void Widget::on_textEdit_redoAvailable(bool b)
{
    qDebug()<<"redoAvailable：重做功能可用"<<b<<Qt::endl;
    //重做就是：Ctrl+Y 重做 = 把刚撤销的内容恢复回来
    //撤销就是：Ctrl+Z 撤销 = 把刚才的修改内容恢复回来
}


//至于是QTextEdit这个控件中的信号copyAvailable 就是当我们选中QTextEdit控件中的内容的时候就会触发
void Widget::on_textEdit_copyAvailable(bool b)
{
    qDebug()<<"copyAvailable：复制功能可用"<<b<<Qt::endl;
}








