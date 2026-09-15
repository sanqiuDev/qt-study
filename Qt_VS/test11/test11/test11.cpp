#include "test11.h"
#include <Qpainter>

#include <QTextDocument>
#include <qDebug>
#include <QAbstractTextDocumentLayout>

test11::test11(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    //先简单的实现绘制Html文本
    
}

test11::~test11()
{}

void test11::paintEvent(QPaintEvent * event)
{
    //1.搞好画家和画笔
    QPainter painter(this);
    painter.setPen(QPen(Qt::red, 5));
    
    //2.将html内容转化成富文本
    QTextDocument doc;
    doc.setHtml(R"(
        <p>写一些html的内容：这是第一行</p>
        <p><b>第二行加粗</b></p>
        <p><span style="color:red;font-size:18px">第三行红色的字</span></p>
    )"
    );

    //偏移绘制起点，整体文本向右下移动20像素
    painter.translate(20, 20);    //记得要是使用的话就在绘制之前使用

    
    //3.限制每行显示富文本的内容
    doc.setPageSize(QSizeF(100, 100));


    //4.将富文本的内容绘制出来
    doc.drawContents(&painter);

    /*
        获取布局管理器
            1.类型：QAbstractTextDocumentLayout
            2.获取：documentLayout()
    */
    QAbstractTextDocumentLayout* layout = doc.documentLayout();

    /*
        获取排版后的整体尺寸
            1.类型：QSizeF
            2.获取：documentSize()   注意使用这个成员函数需要包含头文件：<QAbstractTextDocumentLayout>
    */
    QSizeF docSize = layout->documentSize();

    qDebug() << "排版宽：" << docSize.width() << " 排版高：" << docSize.height();






    //设置绘制上下文的文字颜色，使用传入的clr
    QAbstractTextDocumentLayout::PaintContext context;
    context.palette.setColor(QPalette::Text, Qt::blue);
    //QPalette::Text 代表普通文本颜色。
    //含义：本次绘制富文本时，没有在 HTML 里指定颜色的文字，统一渲染成蓝色；HTML 写死颜色的文字不受这个设置影响。
    //优先级：HTML 内联 style 颜色 > PaintContext 调色板颜色 > QTextDocument 默认字体颜色

    /*
        QAbstractTextDocumentLayout::PaintContext 是布局绘制时的临时绘制参数包，它只作用于这一次 layout->draw() 渲染。
        context.palette 就是这一轮绘制用的调色板
    */

    //9.使用layout绘制文档内容到painter
    layout->draw(&painter, context);


}

