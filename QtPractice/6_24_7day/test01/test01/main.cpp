/*
#include "test01.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    test01 window;
    window.show();
    return app.exec();
}
*/

#pragma execution_character_set("utf-8")

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <QFontDatabase>
#include <QFont>
#include <QString>
#include <QStringList>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    w.setWindowTitle("QFileInfoList + entryInfoList + 字体加载 Demo");
    w.resize(1000, 600);
    QVBoxLayout* layout = new QVBoxLayout(&w);
    layout->setContentsMargins(20, 20, 20, 20);

    QString logText;
    // 1. 获取程序exe所在目录
    QString exePath = QCoreApplication::applicationDirPath();
    QDir dir(exePath);
    logText += QString("程序根目录：%1\n\n").arg(dir.absolutePath());

    // 2. entryInfoList 获取当前目录所有文件信息，存入 QFileInfoList
    QFileInfoList fileInfoList = dir.entryInfoList(
        QDir::AllEntries | QDir::NoDotAndDotDot // 全部条目，过滤 . ..
    );

    logText += "===== 遍历目录全部文件（QFileInfoList）=====\n";
    for (const QFileInfo& info : fileInfoList)
    {
        // absoluteFilePath：完整绝对路径
        QString fullPath = info.absoluteFilePath();
        QString suffix = info.suffix();
        qint64 fileSize = info.size();
        QString type = info.isDir() ? "文件夹" : "文件";

        logText += QString("路径：%1\n类型：%2 | 后缀：%3 | 大小：%4 字节\n\n")
            .arg(fullPath).arg(type).arg(suffix).arg(fileSize);
    }

    // 3. 演示 QFontDatabase::addApplicationFont 加载字体
    QString fontPath = dir.filePath("testfont.ttf");
    QFileInfo fontInfo(fontPath);
    if (fontInfo.exists() && fontInfo.isFile())
    {
        int fontId = QFontDatabase::addApplicationFont(fontPath);
        if (fontId >= 0)
        {
            QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
            if (!fontFamilies.isEmpty())
            {
                QString fontFamily = fontFamilies.first();
                logText += QString("===== 字体加载成功 =====\n字体文件：%1\n字体家族名：%2\n")
                    .arg(fontPath).arg(fontFamily);

                // 使用自定义字体展示文本
                QLabel* fontLabel = new QLabel("测试自定义字体文字");
                QFont customFont(fontFamily, 16);
                fontLabel->setFont(customFont);
                layout->addWidget(fontLabel);
            }
        }
        else
        {
            logText += "===== 字体加载失败，文件损坏或非ttf/otf =====\n";
        }
    }
    else
    {
        logText += "===== 未找到字体文件 testfont.ttf，跳过字体加载 =====\n";
    }

    // 输出日志文本框
    QLabel* logLabel = new QLabel(logText);
    logLabel->setWordWrap(true);
    logLabel->setStyleSheet("font-size:30px;");
    layout->addWidget(logLabel);

    w.show();
    return a.exec();
}