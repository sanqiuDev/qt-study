#include "widget.h"
#include "ui_widget.h"

#include <QLabel>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_add_clicked()
{
    //第一步：创建标签
    //1.数量
    int count = ui->tabWidget->count();
    //2.QWidget
    QWidget *widget = new QWidget();
    //3.标签的标题
    ui->tabWidget->addTab(widget,"标签页"+QString::number(count));

    //第二步：创建标签的内容
    QLabel *label = new QLabel(widget);
    label->setText("标签页"+QString::number(count));

    //第三步：设置标签被选中
    ui->tabWidget->setCurrentIndex(count);

}

void Widget::on_pushButton_delete_clicked()
{
    //第一步：获取当前选中的标签的下标
    int index = ui->tabWidget->currentIndex();

    //第二步：直接删除该标签页
    ui->tabWidget->removeTab(index);
}



//这里我们再来展示一个内容就是：QTabWidget控件的一个信号：currentChanged
void Widget::on_tabWidget_currentChanged(int index)
{
    qDebug()<<"当前选中的标签页的索引是："<<index;
}






