//#pragma execution_character_set("utf-8")

#include "test02.h"

#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QPushButton>

test02::test02(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    this->setObjectName(QStringLiteral("我的名字叫test02 window"));

    //创建一个标签
    QLabel* label = new QLabel(QStringLiteral("我是一个标签"), this);
    label->move(300, 150);
    label->setObjectName(QStringLiteral("label"));

    //创建一个文本
    QTextEdit* textEdit = new QTextEdit(QStringLiteral("我是一个文本："));
    textEdit->setParent(this);
    textEdit->resize(500, 100);
    textEdit->setObjectName(QStringLiteral("textEdit"));

    //追加：
    //textEdit->append(label->parent()->objectName());   
    //覆盖：
    textEdit->setText(textEdit->toPlainText() + label->parent()->objectName());
    /*
       分段拆开解释
        1. textEdit->toPlainText()
            textEdit 是你的多行文本框控件指针
            toPlainText()：函数作用是获取文本框当前里面所有的纯文本内容，返回值类型是 QString
            举例：文本框现在显示「我是一个文本：」，这一段就拿到字符串 "我是一个文本："

        2. label->parent()
            label 是前面创建的 QLabel 标签指针
            parent()：QObject 内置函数，获取这个 label 的父对象指针（你创建 label 时传了this，父对象就是当前窗口 test02）
            返回类型：QWidget*

        3. label->parent()->objectName()
            objectName()：获取控件设置的对象名称，返回 QString
            默认情况下，如果你没手动调用setObjectName("xxx")，返回空字符串 ""

        4. + 字符串拼接
            两个QString之间可以直接用+拼接：
            plaintext
            "我是一个文本：" + "窗口对象名" = "我是一个文本：窗口对象名"

        5. textEdit->setText(拼接后的字符串)
            setText()：覆盖式设置文本框全部内容，会把文本框原有文字全部替换成拼接后的新字符串。
            举个完整运行例子
            textEdit 初始文字：我是一个文本：
            label 的父对象是当前窗口，窗口没设置 objectName，返回空字符串
            执行代码后，文本框文字不变；
            如果给窗口设置名字：this->setObjectName("主测试窗口");
            执行这行代码后，文本框内容变为：我是一个文本：主测试窗口
    */
    
    //如何展示widget窗口的子控件有哪些？
    QTextEdit* textEdit2 = new QTextEdit(QStringLiteral("第一种方式："),this);
    textEdit2->resize(500, 100);
    textEdit2->move(500, 500);
    textEdit2->setObjectName(QStringLiteral("textEdit2"));


    //第一种方式
    textEdit2->setText(textEdit2->toPlainText() + this->children().first()->objectName());

    //第二种方式： window.children() 的返回值是 QList<QObject*>（对象指针列表）
    for (QObject* obj : this->children())
    {
        textEdit2->append(obj->objectName());
    }

}

test02::~test02()
{}

