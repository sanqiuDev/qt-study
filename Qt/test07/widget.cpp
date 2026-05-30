#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //注意细节：就是下面使用了rand函数，这里需要种随机化种子
    srand(time(0));

}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_game_clicked()
{
    //之前我们在学习移动角色的时候，是使用geometry获取当前控件完整的 “位置和尺寸信息”

    //1.获取当前窗口的宽度和高度
    int width = geometry().width();
    int height = geometry().height();

    //2.随机生成新的位置坐标
    int new_x=rand()%width;
    int new_y=rand()%height;


    //3.将按钮移动的指定的位置
    ui->game->move(new_x,new_y);
}

void Widget::on_homework_clicked()
{
    ui->homework->setText("真听话，好好写作业哦");
}

void Widget::on_eat_pressed()
{
    //1.获取当前窗口的宽度和高度
    int width = geometry().width();
    int height = geometry().height();

    //2.随机生成新的位置坐标
    int new_x=rand()%width;
    int new_y=rand()%height;


    //3.将按钮移动的指定的位置
    ui->eat->move(new_x,new_y);
}
