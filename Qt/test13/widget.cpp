#include "widget.h"
#include "ui_widget.h"


#include <QButtonGroup>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //1. 定义的单选按钮的分组
    QButtonGroup * group1 =  new QButtonGroup(this);
    QButtonGroup * group2 = new QButtonGroup(this);
    QButtonGroup * group3 = new QButtonGroup(this);


    //2. 将单选按钮添加到不同的分组中
    group1->addButton(ui->radioButton);
    group1->addButton(ui->radioButton_2);
    group1->addButton(ui->radioButton_3);

    group2->addButton(ui->radioButton_4);
    group2->addButton(ui->radioButton_5);
    group2->addButton(ui->radioButton_6);

    group3->addButton(ui->radioButton_7);
    group3->addButton(ui->radioButton_8);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QString str="今天的任务是：";

    if(ui->checkBox->isChecked()==true)
    {
        str+="工作 ";
    }
    if(ui->checkBox_2->isChecked()==true)
    {
        str+="睡觉 ";
    }
    if(ui->checkBox_3->isChecked()==true)
    {
        str+="玩游戏 ";
    }
    if(ui->checkBox_4->isChecked()==true)
    {
        str+="看电影 ";
    }

    //3. 将最终字符串设置到label中
    ui->label_4->setText(str);
}




















