#include "dialog.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QString>

Dialog::Dialog()
{
    //1.竖直布局管理器
    QVBoxLayout *layout = new QVBoxLayout(this);


    //2.创建控件
    textEdit = new QTextEdit(this);
    QPushButton *pushButton1 = new QPushButton("修改标题",this);
    QPushButton *pushButton2 = new QPushButton("关闭对话框",this);

    //3.将控件都添加到布局管理器中
    layout->addWidget(textEdit);
    layout->addWidget(pushButton1);
    layout->addWidget(pushButton2);


    //4.将信号和槽函数进行绑定
    connect(pushButton1,&QPushButton::clicked,this,&Dialog::handle);
    connect(pushButton2,&QPushButton::clicked,this,&Dialog::close);
}

void Dialog::handle()
{
    QString str = textEdit->toPlainText();
    this->setWindowTitle(str);
}




