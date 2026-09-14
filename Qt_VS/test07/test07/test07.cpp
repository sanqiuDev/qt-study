#include "test07.h"

#include <QLabel>
#include <QFont>

test07::test07(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    //展示两个不同的设置字体的方法
    /*
         颜色
         大小
         字体
         粗细
         倾斜
         下划线
         字距
    */

    //方法一：使用QSS
    QLabel* label = new QLabel(this);
    label->setGeometry(20, 20, 250, 50);
    label->setText("上周六实习结束回来了，今天是周一");

    label->setStyleSheet(R"(
        QLabel
        {
            color:red;
            font-size:13px;
            font-family:"Microsoft YaHei";
            font-weigth:bold;
            font-style:italic;
            text-decoration:underline;
            letter-spacing:2px;
        }
    )");


    //方法二：使用api
    QLabel* label2 = new QLabel(this);
    label2->setGeometry(100, 100, 300, 50);
    label2->setText("上周六实习结束回来了，今天是周一");

    //part1
    QFont f = font();
    f.setPixelSize(16);  //单位是px，setPointSize的单位是pt
    f.setFamily("SimSun");
    f.setBold(true);     //简单的是否加粗，set为weigth可以配合枚举值精准控制有多粗
    f.setItalic(true);
    f.setUnderline(true);
    label2->setFont(f);
    
    //part2
    QPalette p = palette();
    p.setColor(QPalette::WindowText, QColor(Qt::red));  //p.setColor(角色, 颜色)
    label2->setPalette(p);

}

test07::~test07()
{}

