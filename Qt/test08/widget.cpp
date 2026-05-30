#include "widget.h"
#include "ui_widget.h"


#include <QDebug>
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    //在wiget.cpp文件的构造函数Widget中我们可以
    //1）定义局部控件 2）使用connect关联信号和槽 3）创建窗口图标QIcon  4）设置光标的形状QCursor
    //5）设置字体对象QFont 6）创建图片对象QPixmap
    QIcon icon(":/cat.png");
    this->setWindowIcon(icon);

    QCursor cursor(Qt::WaitCursor);
    ui->pushButton->setCursor(cursor);


    //除了使用官方提供的光标之外，我们还可以自定义光标的形状
    //1. 访问到图片文件
    QPixmap pixmap(":/cat.png");
    pixmap=pixmap.scaled(45,45); //缩放图片大小为：45x45

    //2.构造光标对象
    QCursor cursor1(pixmap,10,10);

    //3.将图片放到光标对象中
    this->setCursor(cursor1);



    //这里我们看一看font属性
    //1. 首先先顶一个label对象
    QLabel* label = new QLabel(this);
    label->setText("这是一段文本");

     //2.创建字体对象
     QFont font;
     font.setFamily("黑体");   //字体
     font.setPixelSize(50);   //大小
     font.setBold(true);       //加粗
     font.setItalic(true);     //倾斜
     font.setUnderline(true);  //下划线
     font.setStrikeOut(true);   //删除线


     //3.把字体对象设置label中
     label->setFont(font);


     //为按钮添加是提示信息
     ui->pushButton_4->setToolTip("别信，点击没反应");
     ui->pushButton_4->setToolTipDuration(2000); //2秒提示

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
//    ui->Widget->setWindowTitle("新的窗口标题");
      this->setWindowTitle("新的窗口标题");
    setWindowTitle("我也能设置标题");

}




void Widget::on_pushButton_2_clicked()
{
    //1.获取窗口现在的透明度
    float opacity = this->windowOpacity();
    if(opacity>=1) return;

    //2.输出当前窗口透明度的值
    qDebug()<<"当前的透明度是："<<opacity<<Qt::endl;

    //3.重新调整透明度并进行设置
    opacity+=0.1;
    this->setWindowOpacity(opacity);
}

void Widget::on_pushButton_3_clicked()
{
    //1.获取窗口现在的透明度
    float opacity = this->windowOpacity();
    if(opacity<=0) return;

    //2.输出当前窗口透明度的值
    qDebug()<<"当前的透明度是："<<opacity<<Qt::endl;

    //3.重新调整透明度并进行设置
    opacity-=0.1;
    this->setWindowOpacity(opacity);
}
