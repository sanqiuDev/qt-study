#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>
#include <QDebug>
#include <time.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    srand((unsigned int)time(NULL));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_work_clicked()
{
    //创建消息对话框
    QMessageBox *messageBox = new QMessageBox(this);
    messageBox->setAttribute(Qt::WA_DeleteOnClose);

    messageBox->setWindowTitle("弹窗");
    messageBox->setText("你真乖");

    messageBox->exec();

}

void Widget::on_pushButton_sleep_clicked()
{
    //1. 窗口的长宽
    int win_width = this->geometry().width();
    int win_height = this->geometry().height();

    //2. 按钮的长宽
    int btn_width = ui->pushButton_sleep->geometry().width();
    int btn_height = ui->pushButton_sleep->geometry().height();

    //3.生成按钮新生成的位置
    int new_x = rand()%(win_width - btn_width);
    int new_y = rand()%(win_height - btn_height);

    //4.设置按钮的新位置
    ui->pushButton_sleep->move(new_x,new_y);
}

void Widget::on_pushButton_eat_pressed()
{
    //1. 窗口的长宽
    int win_width = this->geometry().width();
    int win_height = this->geometry().height();

    //2. 按钮的长宽
    int btn_width = ui->pushButton_eat->geometry().width();
    int btn_height = ui->pushButton_eat->geometry().height();

    //3.生成按钮新生成的位置
    int new_x = rand()%(win_width - btn_width);
    int new_y = rand()%(win_height - btn_height);

    //4.设置按钮的新位置
    ui->pushButton_eat->move(new_x,new_y);
}
