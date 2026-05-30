//#include "widget.h"
//#include "ui_widget.h"

//Widget::Widget(QWidget *parent)
//    : QWidget(parent)
//    , ui(new Ui::Widget)
//{
//    ui->setupUi(this);
//}

//Widget::~Widget()
//{
//    delete ui;
//}


//第一部分：头文件的包含 ---> 注意细节就是：头文件都是使用"" 包含的
#include "widget.h"     //自定义头文件的包含
#include "ui_widget.h"  //UI自动生成的头文件

#include <QLabel>
#include "mylabel.h"

#include <QPushButton>

//第二部分：实现构造函数
Widget::Widget(QWidget *parent):QWidget(parent),ui(new Ui::Widget)
{
    ui->setupUi(this);


    //1.先定义一个标签：lable
//    QLabel *lable = new QLabel(this);  //注意使用Qlable的话需要包含头文件<QLabel>
//    lable->setText("hello world");
    MyLabel *lable = new MyLabel(this);  //注意使用Qlable的话需要包含头文件<QLabel>
    lable->setText("hello world");


    //在widget.h文件中的Widget类：
    //除了可以定义一些控件之外（无论是“官方提供”，还是自己继承官方自定义的），还可以
    //将“控件”和“槽函数绑定” ---> connect(哪个控件发出的信号，发出了什么信号，哪个对象进行处理，这个对象怎么处理)
    //本质上就是：connect(控件，信号地址，对象，槽函数地址)
    connect(ui->pushButton,&QPushButton::clicked,this,&Widget::handleClick);



    //也可以纯使用代码来写
//    QPushButton *pushButton1 = new QPushButton(this);
//    pushButton1->setText("我是按按");
    // connect(ui->pushButton1,&QPushButton::clicked,this,&Widget::handleClick1);
    /*
     这里有两个致命错误：
      1. pushButton1 是纯代码创建的对象，它不是 Qt Designer 里拖出来的控件，所以 ui-> 里根本没有这个成员
      2. 如果你一定要用单独的槽函数，需要把 pushButton1 设为类成员变量
    */

   /*
    一句话：因为局部变量 “活不到” 槽函数被调用的时候，而且别的函数根本看不见它。下面拆开讲，很简单。

    1. 作用域问题：局部变量 “别人看不见”
    你在构造函数里这样写：
        Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
        {
            ui->setupUi(this);

            QPushButton *pushButton1 = new QPushButton(this); // 局部变量
            pushButton1->setText("我是按按");
            connect(pushButton1, &QPushButton::clicked, this, &Widget::handleClick1);
        }

        // 槽函数
        void Widget::handleClick1()
        {
            pushButton1->setText("我是扭扭"); // ❌ 编译错误：找不到 pushButton1
        }

        pushButton1 是构造函数里的局部变量，只在 { ... } 内部有效。
        一旦离开构造函数，这个变量名就消失了，handleClick1 完全不认识它。
        👉 解决：把它变成类的成员变量，整个类的所有函数都能看见：
        class Widget : public QWidget
        {
            ...
        private:
            QPushButton *pushButton1; // 成员变量，整个类都能用
        };

    2. 生命周期问题：局部变量 “死得太早”
    就算你用 Lambda，不写单独槽函数：
        void Widget::Widget(...)
        {
            QPushButton *pushButton1 = new QPushButton(this);
            connect(pushButton1, &QPushButton::clicked, this, [&]() {
                pushButton1->setText("我是扭扭"); // ❌ 危险！
            });
        }
    pushButton1 是局部变量，构造函数结束后，变量本身就销毁了（虽然 new 出来的按钮对象还在）。
    Lambda 里的 pushButton1 变成野指针，点击时程序可能崩溃。
    👉 只有把它设为成员变量，才能保证：只要窗口（Widget）还在，pushButton1 就一直有效；槽函数随时可以安全访问它。

    3. 和 ui->xxx 的区别
        ui->pushButton：是 Qt Designer 自动生成的成员变量，所以所有函数都能用；
        你自己 new 的按钮：默认是局部变量，必须手动提升为成员变量才能在槽函数用。
        总结（记住这两句）
        局部变量：出了函数就看不见、就失效；要在多个函数（尤其是槽函数）里用，必须是类成员变量。
    */

    //第一种方式：使用lamba表达式直接构造函数中实现槽函数
    QPushButton *pushButton1 = new QPushButton(this);
    pushButton1->setText("我是按按");
    connect(pushButton1, &QPushButton::clicked, this, [=]() {
        // 直接在 lambda 里处理，不用单独写槽函数，更简单
        if (pushButton1->text() == "我是按按") {
            pushButton1->setText("我是扭扭");
        } else {
            pushButton1->setText("我是按按");
        }
    });
    pushButton1->move(200,400);

    //第二种方式：将pushButton对象定义成全局的对象
    pushButton2 = new QPushButton(this);
    pushButton2->setText("我也是按按");
    connect(pushButton2,&QPushButton::clicked,this,&Widget::handleClick1);
    pushButton2->move(400,400);
}
/*
1. 先分清两个完全不同的类
    你写的窗口类：Widget（继承 QWidget，自己写的）
    Qt 自动生成的 UI 类：Ui::Widget（在 Ui 命名空间里，由 uic 工具从 .ui 生成）
相当于：
namespace Ui {          // 命名空间 Ui
    class Widget;       // 里面有一个类，名字叫 Widget
}
所以：
    Widget ≠ Ui::Widget
    Ui::Widget 才是 UI 类的全名



一句话说清：new Ui::Widget 就是在调用 Ui::Widget 的默认构造函数，只是写法上可以省略括号。
1. 先回到你熟悉的 C++
正常写：
    // 1. 有括号：显式调用默认构造
    MyClass *p1 = new MyClass();

    // 2. 没括号：同样是调用默认构造
    MyClass *p2 = new MyClass;

对 ** 默认构造函数（无参）** 来说：
new MyClass 和 new MyClass() 都会调用构造函数，效果几乎一样。
区别只在：加括号会把基本成员零初始化，不加则不初始化；但对 Qt UI 类影响很小。
所以：
    ui(new Ui::Widget)
    // 等价于
    ui(new Ui::Widget())
    两种写法都在调用 Ui::Widget 的构造函数。
*/

Widget::~Widget()
{
    delete ui;
}


//初始时候这个widget.cpp文件中就是：
//头文件、构造函数，析构函数，然后就没有，
//其实后面还能写其他的函数，主要是看Widget.h文件的构造函数中是不是有声明的其他函数
void Widget::handleClick()
{
    if(ui->pushButton->text()==QString("按钮"))
    {
        ui->pushButton->setText("阿牛");
    }
    else
    {
        ui->pushButton->setText("按钮");
    }
}

void Widget::handleClick1()
{
    if(pushButton2->text()==QString("我也是按按"))
    {
        pushButton2->setText("我也是扭扭");
    }
    else
    {
        pushButton2->setText("我也是按按");
    }
}















