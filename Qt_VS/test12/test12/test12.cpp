#include "test12.h"


//1.实现类
class test12Private
{
public:
    //1.1：两个成员
    QString text;
    int count = 0;

    //1.2：一个函数
    void internalCalc()
    {
        count++;
    }
};


//剩下就是实现class test12里面成员函数了
//尤其注意一下：构造和析构函数是怎么写的
test12::test12(QWidget *parent)
    : QMainWindow(parent),d_ptr(new test12Private())   //注意这个指针是怎么构造的
{
    ui.setupUi(this);


}

test12::~test12()
{
    delete d_ptr;
}


//设置
void test12::setText(const QString & str)
{
    d_ptr->text = str;
    d_ptr->internalCalc();
}

//获取
QString test12::text() const
{
    return d_ptr->text;
}



