#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    //图标是一个好东西，今天我们来尝试一下：
    /*
        1. 为光标创建图标
        2. 为按钮创建图标
    */
    //为光标创建图标
    //1.创建图片对象
    QPixmap pixmap(":/cat.png");
    pixmap=pixmap.scaled(35,35);  //注意：这里要将设置好尺寸再复制给自己

    //2.创建光标，并将图片添加到光标中
    QCursor cursor(pixmap,10,10);

    //3.将光标添加窗口中
    this->setCursor(cursor);



    //为按钮创建图片
    //1.创建图标对象
    QIcon icon(":/cat.png");

    //2.创建按钮，并将图标添加到按钮中
    ui->catt->setIcon(icon);
    ui->catt->setIconSize(QSize(50,50));  //注意：里面放的QSize()，不是直接指定长X宽


    ui->catt->resize(50,50);



    //为鼠标设置连发功能
    ui->pushButton_up->setAutoRepeat(true);
    ui->pushButton_left->setAutoRepeat(true);
    ui->pushButton_down->setAutoRepeat(true);
    ui->pushButton_right->setAutoRepeat(true);
    //为键盘设置快捷键功能
    ui->pushButton_up->setShortcut(QKeySequence("w"));
    ui->pushButton_left->setShortcut(QKeySequence("a"));
    ui->pushButton_down->setShortcut(QKeySequence("s"));
    ui->pushButton_right->setShortcut(QKeySequence("d"));

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_up_clicked()
{
    //1.获取猫咪现在的位置
    QRect ret=ui->catt->geometry();

    //2.设置猫咪的新的位置
    ui->catt->setGeometry(ret.x(),ret.y()-5,ret.width(),ret.height());
}

void Widget::on_pushButton_left_clicked()
{
    //1.获取猫咪现在的位置
    QRect ret=ui->catt->geometry();

    //2.设置猫咪的新的位置
    ui->catt->setGeometry(ret.x()-5,ret.y(),ret.width(),ret.height());
}

void Widget::on_pushButton_down_clicked()
{
    //1.获取猫咪现在的位置
    QRect ret=ui->catt->geometry();

    //2.设置猫咪的新的位置
    ui->catt->setGeometry(ret.x(),ret.y()+5,ret.width(),ret.height());
}

void Widget::on_pushButton_right_clicked()
{
    //1.获取猫咪现在的位置
    QRect ret=ui->catt->geometry();

    //2.设置猫咪的新的位置
    ui->catt->setGeometry(ret.x()+5,ret.y(),ret.width(),ret.height());
}
