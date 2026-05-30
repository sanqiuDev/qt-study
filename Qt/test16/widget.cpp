#include "widget.h"
#include "ui_widget.h"


#include <QRadioButton>
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //1.设置对齐方式
    ui->label->setText("这是一段文本");
    ui->label->setAlignment(Qt::AlignRight|Qt::AlignTop);

    //2.设置自动换行
    ui->label_2->setText("这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本");
    ui->label_2->setWordWrap(true);

    //3.设置缩进
    ui->label_3->setText("这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本");
    ui->label_3->setIndent(50);

    //4.设置边距
    ui->label_4->setText("这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本");
    ui->label_4->setMargin(50);




    //设置label和radioButton之间的伙伴关系
    ui->label_5->setBuddy(ui->radioButton);
    ui->label_6->setBuddy(ui->radioButton_2);


}

Widget::~Widget()
{
    delete ui;
}

