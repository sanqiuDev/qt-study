#include "widget.h"
#include "ui_widget.h"

#include <QTableWidget>
#include <QTableWidgetItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //第一步：创建3行
    ui->tableWidget->insertRow(0);
    ui->tableWidget->insertRow(1);
    ui->tableWidget->insertRow(2);

    //第二步：创建3列
    ui->tableWidget->insertColumn(0);
    ui->tableWidget->insertColumn(1);
    ui->tableWidget->insertColumn(2);

    //第三步：设置列名
    ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("学号"));
    ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("姓名"));
    ui->tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem("年龄"));


    //第四步：为单元格中添加数据
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("1001"));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem("张三"));
    ui->tableWidget->setItem(0,2,new QTableWidgetItem("20"));

    ui->tableWidget->setItem(1,0,new QTableWidgetItem("1002"));
    ui->tableWidget->setItem(1,1,new QTableWidgetItem("李四"));
    ui->tableWidget->setItem(1,2,new QTableWidgetItem("23"));

    ui->tableWidget->setItem(2,0,new QTableWidgetItem("1003"));
    ui->tableWidget->setItem(2,1,new QTableWidgetItem("王五"));
    ui->tableWidget->setItem(2,2,new QTableWidgetItem("22"));



    //处理一下单行输入框
    ui->lineEdit->setPlaceholderText("请输入列名称");


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_insert_row_clicked()
{
    //1.获取表格的总行数
    int rowcount=ui->tableWidget->rowCount();

    //2.
    ui->tableWidget->insertRow(rowcount);

}

void Widget::on_pushButton_intsert_column_clicked()
{
    //0.准备列名称
    QString string = ui->lineEdit->text();

    //1.获取表格的总列数
    int columncount=ui->tableWidget->columnCount();

    //2.新增一列
    ui->tableWidget->insertColumn(columncount);


    //3.设置列名
    ui->tableWidget->setHorizontalHeaderItem(columncount, new QTableWidgetItem(string));
}

void Widget::on_pushButton_delete_row_clicked()
{
    //1.获取当前光标在第几行
    int row = ui->tableWidget->currentRow();

    //2.指定删除该行
    ui->tableWidget->removeRow(row);
}

void Widget::on_pushButton_delete_column_clicked()
{
    //1.获取当前光标在第几列
    int columns = ui->tableWidget->currentColumn();

    //2.指定删除该列
    ui->tableWidget->removeColumn(columns);
}


