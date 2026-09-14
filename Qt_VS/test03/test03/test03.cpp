#include "test03.h"

#include <QLabel.h>
test03::test03(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    //换一种方式
    label = new QLabel(this);

    //调整一些样式
    label->setText("鼠标没有进入label中");
    label->setGeometry(0, 0, 150, 50);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("background-color:#7a9b05;font-size:10px;color:red;font-family:Microsoft YaHei;");

    //注意这里的细节（我们这里要使用“事件过滤器”）
    label->installEventFilter(this);
}

test03::~test03()
{}

bool test03::eventFilter(QObject * obj, QEvent * event)
{
    //判断控件是不是label ---> 判断事件是不是进入
    if (obj == label)
    {
        if (event->type() == QEvent::Enter)  //注意：QEvent::Enter
        {
            label->setText("进入label中了");
            label->resize(500, 500);

            //label->setStyleSheet("background-image:url(:/66d9baf012593967f09459edb6586fe5.jpg);");  //记住将图片放到了.qrc文件同级或者子级的目录中
            //注意这里是，:后面接 ---> url(:/xxx.png);

            label->setStyleSheet(R"(
            QLabel{
                    background-image:url(:/66d9baf012593967f09459edb6586fe5.jpg);   
                    background-repeat:no-repeat;   
                    background-position:center;          
                    background-size:cover; 
            }
            )");

            /* 禁止图片平铺重复 */
            /* 禁止图片平铺重复 */
            /* 覆盖：填满label，图片比例不变，会裁切边缘 */   //background-size:cover;
            /*完整显示整张图，不会裁切，会留空白 */           //background-size:contain;   



            QPixmap pix(":/66d9baf012593967f09459edb6586fe5.jpg");
            label->setPixmap(pix);
            label->setScaledContents(true); // ✅ 开启：图片自动缩放适配label大小
        } 

        else if (event->type() == QEvent::Leave)
        {
            label->setText("鼠标没有进入label中");
            label->setGeometry(0, 0, 150, 50);
            label->setAlignment(Qt::AlignCenter);
            label->setStyleSheet("background-color:#7a9b05;font-size:10px;color:red;font-family:Microsoft YaHei;");
        }

    }

    // 其他事件交给Qt默认处理
    return QMainWindow::eventFilter(obj, event);
}


