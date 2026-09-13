#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //1.创建表单布局管理器
    QFormLayout *layout = new QFormLayout();

    //2.创建三个label作为第一列
    QLabel *label1 = new QLabel("国籍：",this);
    QLabel *label2 = new QLabel("民族:",this);
    QLabel *label3 = new QLabel("电话:",this);

    //3.创建三个lineEdit作为第二列
    lineEdit1 = new QLineEdit(this);
    lineEdit2 = new QLineEdit(this);
    lineEdit3 = new QLineEdit(this);

    //注意细节：
    /*
        // 错误：重新创建局部变量，覆盖成员
        QLineEdit *lineEdit1 = new QLineEdit(this);
    */

    //4.将上述的所有控件都添加到表单布局管理器当中
    layout->addRow(label1,lineEdit1);  //注意：这里将控件添加布局管理器当中使用接口函数是：addRow而不是什么addWidget
    layout->addRow(label2,lineEdit2);
    layout->addRow(label3,lineEdit3);

    //5.最后将整个布局管理器添加的窗口界面上
    this->setLayout(layout);

    //最后这个按钮我们也纯使用代码进行创建，并且将其添加QFromLayout控件的里面
    QPushButton *pushButton1 = new QPushButton("提交（使用纯代码编写）",this);
    layout->addRow(nullptr,pushButton1);

    connect(pushButton1,&QPushButton::clicked,this,&Widget::handle); //注意两个细节：1.是Widget不是QWidget 2.handle后面没有()
    /*
        &Widget::handle()：handle() 是执行调用这个函数，得到返回值，&无法对临时返回值取地址；
        &Widget::handle：取成员函数指针，是 Qt connect 语法要求。

    */

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    qDebug()<<"用户填写的内容是："<<Qt::endl
            <<"姓名："<<ui->LineEdit->text()<<Qt::endl
            <<"性别："<<ui->LineEdit->text()<<Qt::endl
            <<"年龄："<<ui->LineEdit_3->text();
}


void Widget::handle()
{
    qDebug()<<"用户填写的内容是："<<Qt::endl
            <<"国籍："<<lineEdit1->text()<<Qt::endl
            <<"民族："<<lineEdit2->text()<<Qt::endl
            <<"电话："<<lineEdit3->text();
}






