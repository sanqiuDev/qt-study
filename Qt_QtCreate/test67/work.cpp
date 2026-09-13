#include "work.h"
#include <time.h>
#include <QTimer>
#include <QThread>

Work::Work(QObject *parent) : QObject(parent)
{

}


//那么在work.cpp文件中就是对头文件的声明的各种的函数完成定义实现（信号不需要实现）
void Work::doWork()
{
    //一个类似于定时器的耗时的任务
    for(int i=10;i>=0;i--)
    {
        //休眠一秒钟
        QThread::sleep(1);
        /*
           🔍 问题原因
            sleep() 不是标准 C++ 函数，不同平台的实现不一样：
            Linux/macOS 下，sleep() 定义在 <unistd.h> 里，参数单位是秒
            Windows 下，标准函数是 Sleep()（大写 S），定义在 <windows.h> 里，参数单位是毫秒


            你包含的 <time.h>、<QTimer>、<QThread> 都不提供 sleep() 函数，所以编译器找不到

           ✅ 两种正确写法（推荐用第二种）
            用 Qt 跨平台的 QThread::sleep()
            这是 Qt 项目里最标准、最跨平台的写法，不需要额外头文件：QThread::sleep(1);
            它会自动适配 Windows/Linux/macOS，而且你已经包含了 <QThread>，直接就能用。
        */

        /* 这里有一个小的疑问就是：
             为什么我之前使用重写继承自QThread的run函数的时候
             内部也使用了sleep函数，但是为什么我没使用QThread进行作用域解析
             也可以使用

           区别在于：
              静态成员：属于类，子类可以直接用（类名可选），被隐藏时需要加 父类名::
              非静态成员：属于对象，子类对象拥有它们，直接继承访问（除非父类将其声明为 private）

              对，完全一样。普通成员函数也会触发隐藏。规则是：只要派生类中声明了同名函数
              （无论参数是否相同，无论是否是静态），就会隐藏基类中所有同名函数。
              C++ 的名字查找规则是：先在当前作用域查找名字，找到了就不再往上找，所以派生类中的名字会直接屏蔽基类中的所有同名函数。
        */

        //发射ui界面发生更改的信号
        emit sendNum(i);
    }


    //循环结束，耗时任务执行结束，发射任务结束的信号
    emit workFinished();
}


/*
   它们是 Qt 的代码生成工具，在标准编译之前运行：
       moc（Meta-Object Compiler ）— 扫描含 Q_OBJECT 宏的头文件，生成 moc_*.cpp，提供信号/槽、属性、运行时类型信息等元对象功能
       uic（User Interface Compiler）— 将 Qt Designer 输出的 .ui XML 文件编译成 ui_*.h C++ 头文件，内含界面布局和控件的创建代码
       rcc（Resource Compiler）— 将 .qrc 资源文件中列出的图片、样式表、字体等二进制数据打包成 qrc_*.cpp，嵌入到可执行文件中

        - moc — 元对象编译器
        - uic — 用户界面编译器
        - rcc — 资源编译器

    qmake — 跨平台构建系统工具，读取 .pro 项目文件生成 Makefile 或 Visual Studio 工程，并自动调用 moc/uic


Qt 代码在标准的四阶段之前多了一层代码生成步骤：
原始源码                         生成的 C++ 代码              标准编译流程
┌──────────────┐    moc    ┌────────────────┐
│ widget.h     │──────────→│ moc_widget.cpp │──┐
│ (含 Q_OBJECT)│           └────────────────┘  │
├──────────────┤    uic    ┌────────────────┐  │
│ form.ui      │──────────→│ ui_form.h      │──┤──→ 预处理 → 编译 → 汇编 → 链接
├──────────────┤    rcc    ┌────────────────┐  │
│ resources.qrc│──────────→│ qrc_resources.cpp│─┘
├──────────────┤           └────────────────┘  │
│ main.cpp     │───────────────────────────────┘
└──────────────┘
moc 读取含 Q_OBJECT 的头文件，生成 moc_*.cpp（元对象代码，信号/槽机制等）；
uic 把 .ui XML 转成 ui_*.h（纯 C++ 头文件）；
rcc 把 .qrc 资源文件编译为 qrc_*.cpp（二进制数据嵌在数组中）。
这些生成的 .cpp 文件和手写的 .cpp 一起进入标准编译流程，最终链接成可执行程序。
qmake/CMake 自动处理这些工具的调用顺序和依赖关系。
*/
