#include "pushbutton.h"


//PushButton::PushButton()
//{

//}

PushButton::PushButton(QWidget *parent):QPushButton(parent){}
/*
    头文件（.h）：写 “有什么函数”——不加类名::
    源文件（.cpp）：写 “函数怎么做”——必须加 类名::，用来绑定到正确的类。
*/

//重写进入按钮的虚函数
void PushButton::enterEvent(QEvent *event)
{
    (void) event;

    //在 C++ 的成员函数里，this 是一个隐含的指针，它指向当前正在调用这个函数的对象
    //在 C++ 的成员函数里，this 是一个隐含的指针，它指向当前正在调用这个函数的对象
    int parent_w =  this->window()->width();
    int parent_h = this->window()->height();
    //注意细节：this->window() 返回的是一个指针，我们需要使用 -> 来访问它的成员函数
    int btn_w = this->width();
    int btn_h = this->height();
//    int btn_w = ui->pushButton_play->width();
//    int btn_h = ui->pushButton_play->height();
    /*
      一句话：你写的是 “自定义按钮类” 的代码，而 ui->xxx 只能在 “主窗口/界面类” 里用，
             自定义按钮类里根本没有 ui 这个东西。

        主窗口类：有 ui，可以 ui->控件名
        自定义控件类（PushButton）：没有 ui，只能用 this 访问自己
    */


    // 2. 生成随机位置（保证按钮不会超出父窗口边界）
    int new_x = rand() % (parent_w - btn_w);
    int new_y = rand() % (parent_h - btn_h);


    this->move(new_x,new_y);
}
