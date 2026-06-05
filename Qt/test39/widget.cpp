#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>
#include <QGridLayout>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //来试一试设置拉伸系数
    //1. 定义网格布局管理器
    QGridLayout *layout = new QGridLayout();

    //2. 定义六个按钮控件
    QPushButton *pushButton1 = new QPushButton("1",this);
    QPushButton *pushButton2 = new QPushButton("2",this);
    QPushButton *pushButton3 = new QPushButton("3",this);
    QPushButton *pushButton4 = new QPushButton("4",this);
    QPushButton *pushButton5 = new QPushButton("5",this);
    QPushButton *pushButton6 = new QPushButton("6",this);
    //2.5：给按钮控件设置水平/垂直策略
    /*
       btn->setSizePolicy(水平方向, 竖直方向);
       参数1：横向宽度伸缩规则，参数2：纵向高度伸缩规则
        第一个：横向 (width) 策略 → 按钮左右能不能拉伸
        第二个：纵向 (height) 策略 → 按钮上下能不能拉伸
        Expanding：控件主动抢占布局多余空白空间，窗口放大时跟着同比例变大

    Fixed	    固定大小，永远跟随文字尺寸，绝不拉伸（按钮默认）
    Minimum     保留最小尺寸，有余量可以拉伸
    Preferred	优先自身尺寸，少量拉伸（QPushButton 默认策略）
    Expanding	强力拉伸，争抢剩余空白
    */
    pushButton1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    pushButton2->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    pushButton3->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    pushButton4->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    pushButton5->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    pushButton6->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);


    //3. 将控件都添加进入布局管理器中
    layout->addWidget(pushButton1,0,0);
    layout->addWidget(pushButton2,0,1);
    layout->addWidget(pushButton3,0,2);
    layout->addWidget(pushButton4,1,0);
    layout->addWidget(pushButton5,1,1);
    layout->addWidget(pushButton6,1,2);


    //4.将布局管理器添加到窗口上
    this->setLayout(layout);


    //5.设置水平拉伸系数
    layout->setColumnStretch(0,0);
    layout->setColumnStretch(1,2);
    layout->setColumnStretch(2,1);

    /*
        ✅ 只对 QGridLayout 网格布局生效，HBox/VBox 不能用
        对应竖向拉伸：setRowStretch(行号,权重)

        宽度分配规则
            剩余可用宽度按照 0:1:2 分配：
            0 列：不占剩余宽度（控件固有大小固定）
            1 列：1/(1+2)=1/3 剩余宽度
            2 列：2/(1+2)=2/3 剩余宽度
    */

    //6.
}

Widget::~Widget()
{
    delete ui;
}

