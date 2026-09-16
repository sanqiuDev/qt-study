#include "test18.h"
#include <QFile>

test18::test18(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    //接着看：QFile
    /*
        QFile 是 Qt 用来读写本地文件的类，继承 QFileDevice，可以读文本、二进制、图片、配置文件。
        头文件：#include <QFile>
        配合 QFileInfo 获取文件信息；配合 QTextStream（文本）/ QDataStream（二进制）读写。

        QFile 和 QFileInfo 的区别（重点区分）
            QFile：操作文件内容（读、写、删）
            QFileInfo：查询文件元信息（大小、修改时间、是否是目录、后缀），不能读写内容

        | 函数                                    | 说明                            |
        | -------------------------------------- | ------------------------------ |
        | QFile(const QString &fileName)         | 构造，传入文件路径               |
        | bool open(OpenMode mode)               | 打开文件，返回成功与否           |
        | qint64 read(char *data, qint64 maxSize)| 读取指定字节                    |
        | QByteArray readAll()                   | 一次性读取全部内容               |
        | QByteArray readLine()                  | 读一行                          |
        | qint64 write(const QByteArray &data)   | 写入字节数组                    |

        | bool flush()                           | 把缓冲区数据刷入磁盘             |
        | void close()                           | 关闭文件；离开作用域析构时会自动 close|
        | bool exists()                          | 判断文件是否存在                 |
        | bool remove()                          | 删除文件                        |
        | bool rename(const QString &newName)    | 重命名文件                      |

    OpenMode 打开模式（常用）
        QIODevice::ReadOnly：只读
        QIODevice::WriteOnly：只写，会清空原有内容
        QIODevice::Append：追加写入，不会覆盖旧内容
        QIODevice::Text：文本模式，Windows 自动转换换行符 \n <-> \r\n；二进制文件不要加这个标志

    Demo1：读取文本文件
    */

    /*------------------------------读取文本------------------------------*/
    //类似于：QPixmap，QDir，QFileInfo 我们这里QFile也是这样定义的

    ////1.
    //QFile file("E:\\Code\\qt-study\\Qt_VS\\test18\\test18\\doc.txt");

    ////2.打开
    //if (!file.open(QIODevice::ReadOnly|QIODevice::Text))
    //{
    //    qDebug() << "文件打开失败：" << file.errorString();
    //    return;
    //}

    ////3.读取
    //QByteArray data = file.readAll();
    //qDebug() << data;

    ////4.关闭
    //file.close();


    /*------------------------------写入文本------------------------------*/
    ////1.
    //QFile file("E:\\Code\\qt-study\\Qt_VS\\test18\\test18\\doc.txt");
    ////2.打开
    //if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    //{
    //    qDebug() << "文件打开失败：" << file.errorString();
    //}
    ////3.写入
    //file.write("hello,world\n");
    //file.write("写第二行");

    ////4.关闭
    //file.close();

    /*------------------------------追加写入------------------------------*/
    //1.
    QFile file("E:\\Code\\qt-study\\Qt_VS\\test18\\test18\\doc.txt");
    //2.打开
    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "文件打开失败：" << file.errorString();
    }
    //3.追加写入
    file.write("\n追加写入一行内容");

    //4.关闭
    file.close();
}

test18::~test18()
{}

