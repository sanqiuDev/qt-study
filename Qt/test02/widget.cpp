#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //这里我们实现一个功能就是：
    //当用户点击按钮的时候，窗口界面就会关闭
    connect(ui->pushButton,&QPushButton::clicked,this,&Widget::close);

    //connect(ui->pushButton_2,&QPushButton::click,this,&Widget::on_pushButton_2_clicked);


    //这里我们验证一下自定义信号，所以这里我们手动将pushButton3绑定到我们自己定义的信号mySignal
    // connect(ui->pushButton_3,&Widget::mySignal,this,&Widget::handle_mySignal); 错位实例
    //注意connect函数的细节：
    //第一个控件是：按钮
    //所以第二个参数&Q按钮::mySignal
    /*
      但是我们有不能给QPushButton创建信号，只能给Widget创建信号
      所以注定connect函数要写成：connect(this,&Widget::自定义的信号函数名,this,&Widget::信号处理函数)
    */
    connect(this,&Widget::mySignal,this,&Widget::handle_mySignal);

    emit mySignal(); //我需要自己手动手动发射
    //我们只能自己这样固定的触发没什么意义，要有交互触发才有意思：
    //所以这个信号的触发时机可以交给QPushButton的click信号触发来决定


    connect(this,&Widget::mySignal,this,&Widget::handle_mySignal2);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_2_clicked()
{
    if(ui->pushButton_2->text()=="你叫什么名字？")
    {
        ui->pushButton_2->setText("我叫Qt");
    }
}

void Widget::handle_mySignal()
{
    if(ui->pushButton_3->text()=="验证的自定义信号")
    {
        ui->pushButton_3->setText("验证成功");
    }
}

void Widget::on_pushButton_4_clicked()
{
     emit mySignal();
    //所以这个信号的触发时机可以交给QPushButton的click信号触发来决定
}

void Widget::handle_mySignal2()
{
    if(ui->pushButton_5->text()=="")
    {
        ui->pushButton_5->setText("💰发生了改变");
    }
}
