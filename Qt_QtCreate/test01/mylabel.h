#ifndef MYLABEL_H
#define MYLABEL_H

#include <QObject>
#include <QWidget>

#include <QLabel>
//这我们确实得到了继承自类QLabel子类MyLabel类
class MyLabel : public QLabel
{
    Q_OBJECT
public:
//    MyLabel();

    //生成的只有一个构造，这里我们就将“构造和析构都声明出来”
    MyLabel(QWidget *parent); //注意头文件中只声明，不定义：没有1）参数列表   2）{}函数体

    /*
        1. 核心原因：和 Qt 的对象树（Parent-Child 机制）强绑定
        在 Qt 中，几乎所有 QWidget 子类的构造函数，都会带一个 QWidget *parent 参数。
            它的作用，是把当前 MyLabel 对象，挂到 parent 控件的对象树上。
        当 parent 控件被销毁时，它会自动销毁自己的所有子控件（包括你的 MyLabel），帮你自动管理内存，避免内存泄漏。
        如果你的 MyLabel 没有这个 parent 参数，就没法被其他 Qt 控件 “托管”，必须手动管理它的释放，很容易出问题。
    */

    ~MyLabel();
};

#endif // MYLABEL_H
