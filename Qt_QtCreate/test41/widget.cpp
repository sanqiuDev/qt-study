#include "widget.h"
#include "ui_widget.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QSpacerItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //这里我们开始演示怎么控件：
    //1.定义水平布局管理器
    QHBoxLayout *layout = new QHBoxLayout();

    //2.定义两个按钮控件
    QPushButton *pushButton1 = new QPushButton("1",this);
    QPushButton *pushButton2 = new QPushButton("2",this);

    //3.定义间距控件
    /*
      QSpacerItem(宽度,高度,横向策略,纵向策略)
      QSpacerItem* spacer = new QSpacerItem(200, 20);
        参数 1：最小宽度 200px
        参数 2：最小高度 20px
        默认：横向Expanding、纵向Fixed，水平布局里横向自动拉伸占空余空间

    */
    QSpacerItem *space = new QSpacerItem(200,20);


    //3.将 “两个按钮控件” + “间距控件” 都添加水平布局管理器中
    layout->addWidget(pushButton1);
    layout->addSpacerItem(space);
    layout->addWidget(pushButton2);
    /*
        效果：[按钮1] ←空白空隙→ [按钮2]
        空隙最小固定宽 200，窗口拉大时空隙会继续拓宽，把两个按钮往左右两边撑开。
    */

    //4.最后水平布局管理器添加到窗口上
    this->setLayout(layout);

}

Widget::~Widget()
{
    delete ui;
}

