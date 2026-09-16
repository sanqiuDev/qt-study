#include "test13.h"

#include <QDir>
#include <QList>
#include <QDebug>

test13::test13(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    /*
    1. QDir：Qt 目录操作类。用来打开文件夹、遍历文件、过滤后缀、创建 / 删除目录、分隔路径。
    2. QFileInfo：单个文件 / 目录信息类，可以拿到文件名、后缀、大小、是否文件夹、绝对路径、修改时间。
    3. QFileInfoList：QList<QFileInfo>，文件信息列表，多个文件信息装在一起。
    4. entryInfoList()：QDir 的成员函数，遍历目录，直接返回 QFileInfoList

    总结：
    过滤器：QList<QString>
    QFileInfoList = QDir.entryInfoList(过滤器)
    for(QFileInfo:QFileInfoList)
*/

//今天我们的任务是：判断E:\Code\qt-study\Qt_VS\test13路径下面
//1.有多少的.json文件(不统计目录)  + 2.文件的基础信息都是什么
    QDir dir("E:\\Code\\qt-study\\Qt_VS\\test13\\test13\\x64\\Debug");   //注意路径：是“/”或者“\\”
    if (!dir.exists())
    {
        qDebug() << "目录不存在";
    }

    //2.创建文件过滤器
    QList<QString> filter;
    filter << "*.json";

    //3.遍历目录
    QList<QFileInfo> infoList = dir.entryInfoList(filter, QDir::Files, QDir::Name);
    /*
        参数 2：QDir::Filters filters 【文件类型过滤器，位或组合 |】

        用来筛选条目是文件 / 文件夹、是否包含.和..、隐藏文件等。
        常用枚举：
        | 标识 | 含义 |
        | --- ------------      | ---                       |
        | QDir::Files           | 只取普通文件（排除文件夹）  |
        | QDir::Dirs            | 只取文件夹                 |
        | QDir::NoDotAndDotDot  | 排除 .（当前目录）、..上级目录，几乎必加 |
        | QDir::Hidden          | 包含隐藏文件                |
        | QDir::NoFilter        | 默认，全部条目都拿           |

        示例组合：
            //文件+文件夹，排除 . 和 ..
            QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot



        参数 3：QDir::SortFlags sort 【排序规则，位或组合 |】

        控制返回列表的顺序：
            | 标识            |           含义            |
            | ---  -----------| --- ---------------------|
            | QDir::Name      | 按文件名排序               |
            | QDir::Size      | 按文件大小                 |
            | QDir::Time      | 按修改时间                 |
            | QDir::DirsFirst | 文件夹排在前面              |
            | QDir::Descending| 降序（默认升序 Ascending）  |
            | QDir::NoSort    | 默认，不排序，读取顺序不确定 |
    */

    //4.看有多少.json文件
    qDebug() << "文件总数是：" << infoList.size();

    //5.看看找到的这些*.json文件更详细的信息
    for (const QFileInfo& info : infoList)
    {
        qDebug() << "========";
        qDebug() << "文件名：" << info.fileName();
        qDebug() << "绝对路径：" << info.absoluteFilePath();
        qDebug() << "文件后缀：" << info.suffix();
        qDebug() << "文件大小(字节)：" << info.size();
        qDebug() << "是否文件夹：" << info.isDir();
        qDebug() << "修改时间：" << info.lastModified();
    }

}

test13::~test13()
{}

