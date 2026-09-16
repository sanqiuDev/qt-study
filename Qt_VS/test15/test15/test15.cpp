#include "test15.h"
#include <QFileInfo>
#include <QDebug>
#include  <QLibrary>
test15::test15(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    /*
        QLibrary::isLibrary(const QString &fileName)
        静态函数，只判断文件名后缀是不是平台动态库后缀，不校验文件内容、不加载文件Qt
            Windows：后缀 .dll 返回 true
            Linux：.so
            Mac：.dylib / .bundle


        absoluteFilePath() 是 QFileInfo 的成员函数，返回文件完整绝对路径字符串（磁盘真实路径）

        它和filePath()区别：
            absoluteFilePath()：绝对完整路径，从盘符开始，D:/xxx/plugin.dll
            filePath()：返回构造 QFileInfo 传入的原始路径（可能是相对路径）
    */

    //这里我们就展示使用一下：QLibrary::isLibrary 和 absoluteFilePath()

    //这里一定要有一个一意识就是：
    //QPixmap 和 QDir 和 QFileInfo 使用上面其实是一模一样的
    QFileInfo fileInfo("vulkan-1.dll");

    QString path = fileInfo.absoluteFilePath();  //通过文件名 ---> 文件的绝对路径
    //顺便看一下：filePath()和它的差别
    QString path2 = fileInfo.filePath();  
    qDebug() << "path:" << path << "\n" << "path2：" << path2;  
    /*
        输出结果是：
        path: "E:/Code/qt-study/Qt_VS/test15/test15/vulkan-1.dll"
        path2： "vulkan-1.dll"
    */

     
    //使用绝对路径看一看这个文件是不是动态库
    if (QLibrary::isLibrary(path))
    {
        qDebug() << "后缀是动态库";
    }
}

test15::~test15()
{}

