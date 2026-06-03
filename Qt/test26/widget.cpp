#include "widget.h"
#include "ui_widget.h"

#include <fstream>
#include <QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //任务：将文件中内容读取出来并添加到QComboBox控件中

    //1. 以只读的方式打来文件 ---> 读文件：数据从磁盘到cpu，所以使用ifstream
//    std::ifstream in("E:\\Code\\qt-study\\Qt\\test26\\file.txt",std::ios::in);
    std::ifstream in("E:/Code/qt-study/Qt/test26/file.txt",std::ios::in); //两种不同的写法
    if(!in.is_open())
    {
        qDebug()<<"文件打开失败"<<Qt::endl;
    }

    //2. 逐行读取文件文件中的内容
    //    QString str;
    std::string str; //注意细节：getline函数接受的参数： C++ 标准std::string，不能接收 Qt 的 QString
    while(std::getline(in,str))
    {
        //3.读取的每行的数据你要怎么办呢？
        ui->comboBox->addItem(QString::fromStdString(str));

        //QString ---> std::string  的接口：QString::fromStdString(std::string)
    }

    //4.关闭文件
    in.close();
}

Widget::~Widget()
{
    delete ui;
}

