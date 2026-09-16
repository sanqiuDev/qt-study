#include "test14.h"
#include <QDir>
#include <QDebug>
#include <QPixmap>
#include <QLabel>
test14::test14(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    //区分两个极易搞混接口：
    //1. applicationDirPath() → exe 所在文件夹 （目录）
    //2. applicationFilePath() → exe 完整全路径，带 exe 文件名
    //属于静态函数，`#include <QCoreApplication>`，GUI 项目也能用（QApplication 继承 QCoreApplication）。

    QDir exe_dir = QApplication::applicationDirPath();
    qDebug() << "exe文件所在的文件夹是" << exe_dir;    //输出：E:/Code/qt-study/Qt_VS/test14/x64/Debug

    QString exe_file = QApplication::applicationFilePath();  //applicationFilePath() 返回的是字符串，不要用 QDir 接收
    qDebug() << "exe文件的路径是" << exe_file;   //输出：E:/Code/qt-study/Qt_VS/test14/x64/Debug/test14.exe

    //然后我们实现exe所在文件夹下面的图片
    //QPixmap pixmap(exe_dir + "/image");
    //路径拼接不要直接 + "/image"
    //直接字符串拼接，容易出现斜杠重复，跨平台不安全。
    //✅ Qt 推荐：用 QDir::filePath() 拼接路径，自动处理 /

    //正确：
    QString imgPath = exe_dir.filePath("image/小虫熊.jpg");  //注意：具体指定图片
    QPixmap pixmap(imgPath);
    //判断是不是空对象
    if (!pixmap.isNull())
    {
        qDebug() << "图片加载成功";
    }
    else
    {
        qDebug() << "图片加载失败";
    }

    QLabel *label = new QLabel(this);
    label->setGeometry(20, 20, 150, 150);
    //使用paintEvent事件能很好的绘制完整的图片，但是将图片放到label中展示经常会显示补全
    //所以要让图片自适应label
    label->setScaledContents(true);

    label->setPixmap(pixmap);


}

test14::~test14()
{

}

