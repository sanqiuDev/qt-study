#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //1. 将label中的内容设置成：“纯文本”
    ui->label->setTextFormat(Qt::PlainText);
    ui->label->setText("<font color='red'>我是红色</font>");

    //2. 将label中的内容设置成：“纯文本”
    ui->label_2->setTextFormat(Qt::RichText);
    ui->label_2->setText("<font color='red'>我是红色</font>");

    //3. 将label中的内容设置成：“纯文本”
    ui->label_3->setTextFormat(Qt::MarkdownText);
    ui->label_3->setText("# 我是红色");

}

Widget::~Widget()
{
    delete ui;
}

