#include "test19.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

test19::test19(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    /*
       整套概念（插件读取 json 配置常用组合）
            1. QJsonDocument：  JSON 文档容器，整个 json 的根对象，可以包含QJsonObject/QJsonArray
            2. QJsonParseError：解析错误信息结构体，接收fromJson的解析失败原因
            3. QJsonDocument::fromJson()：静态函数，把二进制字节数组 QByteArray 解析成 QJsonDocument
            4. QFile::readAll()：一次性读取文件全部字节，返回QByteArray，交给fromJson解析


       QJsonParseError 核心成员

        QJsonParseError::ParseError error：错误枚举
        QJsonParseError::NoError：解析成功
        QJsonParseError::UnterminatedObject 缺少}
        QJsonParseError::UnterminatedArray 缺少]
        QJsonParseError::IllegalValue 非法值、语法写错
        int offset：出错的字节偏移位置，定位 json 哪一行坏了，排错神器
        QString errorString()：返回可读的错误文字



        QFile打开文件 → readAll() → QByteArray原始json文本 → QJsonDocument::fromJson() → 解析内容到QJsonDocument
                                 ↑
                         QJsonParseError捕获语法错误

    */
    
    //1.首先先读取到文件中的内容：
    QFile file("E:\\Code\\qt-study\\Qt_VS\\test19\\test19\\doc.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "文件打开失败：" << file.errorString();
    }
    QByteArray data = file.readAll();
    file.close();

    //2.然后将读取到QByteArray数据转换成QJsonDocument数据
    //注意：由于我们还要顺便看一看有没有解析失败，所以还要定义一个：QJsonParseError
    QJsonParseError jsonError;
    QJsonDocument json = QJsonDocument::fromJson(data, &jsonError); //放指针
    
    if (jsonError.error != QJsonParseError::NoError)
    {
        qDebug() << "解析失败：" << jsonError.errorString();
        return;
    }
   

    //3.解析成功怎么处理
    if (!json.isObject())
    {
        qDebug() << "JSON根不是Object";
        return;
    }
    QJsonObject rootObj = json.object();

    /*
        if (!doc.isObject())
            json 是 QJsonDocument（整个 json 文档）
            json.isObject() 判断：这个 json 最外层是不是大括号 {} 的对象

        ✅ 合法示例（根是 Object，我们想要的）
        {
          "name":"分光插件",
          "version":1
        }


        ❌ 如果根是数组 []，doc.isObject() 返回 false，直接打印提示并 return 退出。
        ["a","b"]
        很多人踩坑：json 文件最外层是数组，调用`.object()`会拿到空对象，读取字段全部为空。所以必须加这个判断。
    */

    // 读取json里面字段示例
    QString name = rootObj["name"].toString();
    int version = rootObj["version"].toInt();
    qDebug() << "name:" << name << " version:" << version;
    
}

test19::~test19()
{}

