#include "test21.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>

test21::test21(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    //今天我们来学习Qt的三种布局
    /*
         水平布局：QHBoxLayout
         垂直布局：QVBoxLayout
         网格布局：GridLayout

       以及和它们相关的几个函数：
            1. setLayout(QLayout*)：给一个 Widget 设置布局管理器（绑定布局）
            2. setContentsMargins(left, top, right, bottom)：布局内边距，布局区域和父控件边框之间的留白
            3. setSpacing(int)：布局内部控件之间的间距（控件与控件空隙）


    一句话区分 margins vs spacing
        contentsMargins：布局盒子外面一圈留白
        spacing：盒子里面各个控件互相之间的距离
    
    */

    //1.修改一下窗口的标题
    setWindowTitle("三种布局的学习");
    //2.重新修改窗口的大小
    resize(1000, 500);


    //1.创建垂直布局、 水平布局、网格布局
    QVBoxLayout* layout1 = new QVBoxLayout();
    QHBoxLayout* layout2 = new QHBoxLayout();
    QGridLayout* layout3 = new QGridLayout();

    //2.调整布局距离外边框“左、上、右、下”各个20px
    layout3->setContentsMargins(50, 20, 50, 20);

    //3.控件和控件之间相隔15像素
    layout3->setSpacing(200);
    
    //在布局中添加三个按钮
    QPushButton* pushButton1 = new QPushButton("按钮1");
    QPushButton* pushButton2 = new QPushButton("按钮2");
    QPushButton* pushButton3 = new QPushButton("按钮3");


    layout3->addWidget(pushButton1);
    layout3->addWidget(pushButton2);
    layout3->addWidget(pushButton3);


    //将布局设置到的窗口上面
    //setLayout(layout);
    ui.centralWidget->setLayout(layout3);
    /*
        test21.cpp:55 把布局直接设在了 QMainWindow 上：
            this->setLayout(layout);   // ❌ 对 QMainWindow 无效
            QMainWindow 内部已有自己的布局（菜单栏、工具栏、中央部件、状态栏，见 ui_test21.h:35-46），
            Qt 明确禁止对它再 setLayout，运行时会直接忽略并打印警告：
                    QMainWindow::setLayout: Can't set a layout on a QMainWindow widget
                    因此这个 QVBoxLayout 从未挂到任何部件上，
                    里面 addWidget 的三个按钮也就永远不会显示——窗口只剩空白的 centralWidget，看起来"什么都没有"。
    
    */
}

test21::~test21()
{}

