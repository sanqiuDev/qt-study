#include "widget.h"
#include "ui_widget.h"


#include <QListWidget>
#include <QListWidgetItem>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //向我的列表控件QListWidget中添加一些元素
    ui->listWidget->addItem("C");
    ui->listWidget->addItem("C++");
    ui->listWidget->addItem("Java");

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_insert_clicked()
{
    //1.内容
    const QString str = ui->lineEdit->text();

    //2.添加
    ui->listWidget->addItem(str);
}

void Widget::on_pushButton_delete_clicked()
{
    //1.判断（如果当前QListWidget中没有内容的时候就需要进行删除了）
    int row = ui->listWidget->currentRow();
    if(row<=0) return;

    //2.删除
    ui->listWidget->takeItem(row);
}



void Widget::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
/*
    QListWidget 切换选中项时自动触发，自带两个参数：
        current：新选中条目指针；无选中 = nullptr
        previous：之前旧选中条目指针；之前没选任何项 = nullptr

    三种场景举例
        空白列表第一次点选项：
            previous=nullptr、current=选中项 → 只打印当前内容
        从 A 切换选中到 B：
            previous=A、current=B → 同时打印上次、当前内容
        取消全部选中：
            current=nullptr、previous=原选项 → 只打印上次内容
*/
{
    if(current!=nullptr)
        qDebug()<<"新选中的条目是："<<current->text();
    if(previous!=nullptr)
        qDebug()<<"之前选中的条目是："<<previous->text();
}










