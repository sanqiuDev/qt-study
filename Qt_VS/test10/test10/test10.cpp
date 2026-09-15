#include "test10.h"

#include <QTextDocument>

#include <QPainter>
#include <QPen>
#include <QBrush>

test10::test10(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    /*
        接下我们来演示：
            1. 控件：QTextDocument
            2. 函数：setHtml，setDefaultFont
    */

    //QTextDocument doc;
    

    //就把它想象成是QLabel,所以接下来我们就是往上面写一些文字内容
    //doc.setText("在QTextDocument的上面写一些文字");

    //doc.setHtml(
    //    R"(
    //    <p>这是默认字体的普通文字</p>
    //    <p><b>加粗文字</b></p>
    //    <p><span style="color:red;font-size:18px;">红色大号文字</span></p>
    //    <p><span style="color:#2E8B57;font-style:italic;">绿色斜体文字</span></p>
    //)"
    //);  

    /*
        在 test10.cpp中，你只是创建了一个局部的 QTextDocument doc 对象，调用 setHtml(...) 设置了 HTML，但存在两个致命问题：
            1. QTextDocument 本身是不可见的 —— 它只是富文本的"数据模型"，必须配合视图控件（QTextEdit、QTextBrowser 等）才能显示出来。你没有把它放到任何视图上。
            2. doc 是构造函数里的局部变量，作用域结束时立刻被析构，里面的内容也跟着没了。
    */
    

    

}

test10::~test10()
{}

void test10::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);

    QPen pen;
    painter.setPen(QPen(Qt::blue, 4));


    //纯文本
    painter.drawText(20, 30,"写纯字符串文本");


    //富文本
    QString text = R"(
        <p>这是默认字体的普通文字</p>
        <p><b>加粗文字</b></p>
        <p><span style="color:red;font-size:18px;">红色大号文字</span></p>
        <p><span style="color:#2E8B57;font-style:italic;">绿色斜体文字</span></p>
    )";
    painter.drawText(20, 50, text);


    QTextDocument text2;  

    //这里的setHtml是功能就是将 “html” 的内容转换成的 “富文本” 形式
    text2.setHtml(R"(
        <p>这是默认字体的普通文字</p>
        <p><b>加粗文字</b></p>
        <p><span style="color:red;font-size:18px;">红色大号文字</span></p>
        <p><span style="color:#2E8B57;font-style:italic;">绿色斜体文字</span></p>
    )"
    );

    // 2. 设置默认字体：全局兜底字体
    QFont f;
    f.setPointSize(14);
    f.setFamily("Microsoft YaHei");
    text2.setDefaultFont(f);
    /*
        setDefaultFont
            设置文档全局默认字体：当 HTML 文本里没有指定字体时，就用这个字体渲染。
            如果 HTML 写死了font-family，这个默认字体就不生效
    */

    //painter.drawText(20, 70, text2);
    text2.drawContents(&painter);

}
