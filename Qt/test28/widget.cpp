#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //任务：实现日期时间计算器
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    //1.首先获取进行计算的两个时间
    QDateTime oldTime = ui->dateTimeEdit->dateTime();
    QDateTime newTime = ui->dateTimeEdit_2->dateTime();

    qDebug()<<oldTime<<Qt::endl
            <<newTime;

    //2.然后将它们都转化为秒数
    //secsTo(目标时间)：新时间更大→seconds>0；旧时间更大→结果为负数
    int seconds = oldTime.secsTo(newTime);

    //3.将秒数换算为天数
    //第一步：计算完整的天数
    int day = (seconds/3600)/24;
    //第二步：多余的小时
    int hour = (seconds/3600)%24;


    QString str = "相差了：\n" + QString::number(day) + "天零" + QString::number(hour) + "小时";
    ui->label->setText(str);

    qDebug()<<"相差了：\n"<<day<<"天零"<<hour<<"小时";

    /*
       这里我们回忆一下类型的转换：
           1. int         ---> QString    QString::nummber(int)
           2. std::string ---> QString    QString::fromStdString(std::string)
    */

}


