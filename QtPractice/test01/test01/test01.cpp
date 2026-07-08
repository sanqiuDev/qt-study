#include "test01.h"

#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>

test01::test01(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    //创建：标签、按钮、单行输入框
    QLabel* label = new QLabel(QStringLiteral("我叫标签"),this);
    label->move(100, 100);
    label->setObjectName(QStringLiteral("标签"));

    QPushButton* pushButton = new QPushButton(QStringLiteral("我叫按钮"), this);
    pushButton->move(250, 250);
    pushButton->setObjectName(QStringLiteral("按钮"));

    QLineEdit* lineEdit = new QLineEdit(QStringLiteral("我叫单行输入框"), this);
    lineEdit->move(350, 350);
    lineEdit->setObjectName(QStringLiteral("单行输入框"));
    /*
      注意这里
        如果我们去掉：lineEdit->setObjectName(QStringLiteral("单行输入框"));
        输入的结果是：最后一个只有：没有后面的内容

        如果我们写成：QLineEdit* lineEdit = new QLineEdit(QStringLiteral("我叫单行输入框"));
        输入的结果是：最后行内容没有了
    */

    //1. children() 获取全部直接子对象
    QList<QObject*> childList = this->children();

    //for (QObject* object : childList)
    //{
    //    //label->append(object->objectName());
    //    /*
    //       label 是 QLabel
    //        QLabel 没有 append() 方法，append() 属于 QTextEdit/QPlainTextEdit 文本编辑框控件。
    //        QLabel 追加文字要用 setText / text() 拼接：

    //        // 错误：label->append()
    //        // 正确写法：
    //    */
    //    QString allText = label->text() + QStringLiteral("：") + object->objectName() + "\n";
    //    label->setText(allText);
    //}

    QString showText = label->text();
    for (QObject* object : childList)
    {
        showText += QStringLiteral("：%1\n").arg(object->objectName());
    }
    label->setText(showText);


    //2. findChild<T>("名称") 根据名字精准查找单个控件
    QPushButton* pushButton1 = findChild<QPushButton*>(QStringLiteral("按钮"));   //注意这里<>中的是指针，因为这个控件是在堆上创建的
    if (pushButton1 != nullptr)
    {
        pushButton->setText(QStringLiteral("找到按钮了"));
    }
    /*
        注意一个细节就是：
        因为：pushButton->setObjectName(QStringLiteral("按钮"));
        所以：这里写 findChild<QPushButton*>(QStringliteral("按钮")); 简单点说就是要添加上QStringLiteral()
        不然的话我们不能找到按钮
    */
}

test01::~test01()
{}

