#pragma execution_character_set("utf-8")
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


#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtCore/QCoreApplication>
#include <QtCore/QFile>
#include <QtCore/QTextStream>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    w.setWindowTitle("executableDir 获取程序目录Demo");
    w.resize(500, 500);

    // 测试，获取exe执行文件的路径(executableDir)
    QString exeDir = QCoreApplication::applicationDirPath();

    // 垂直布局
    QVBoxLayout* layout = new QVBoxLayout(&w);

    //QLabel* labelTip = new QLabel(QStringLiteral("当前执行文件exe所在目录(executableDir)："));
    QLabel* labelTip = new QLabel("当前执行文件exe所在目录(executableDir)：");
    QLabel* labelPath = new QLabel(exeDir);
    labelPath->setStyleSheet("color:#0066cc; font-size:30px;");
    labelPath->setWordWrap(true); // 设置路径自动换行

    layout->addWidget(labelTip);
    layout->addWidget(labelPath);

    // 拼接同级目录下文件路径显示
    QString configFilePath = exeDir + "/config.ini";
    //QLabel* labelFile = new QLabel(QStringLiteral("同级目录下配置文件路径：") + configFilePath);
    QLabel* labelFile = new QLabel("同级目录下配置文件路径：" + configFilePath);
    labelFile->setWordWrap(true);
    layout->addWidget(labelFile);

    w.show();
    return a.exec();
}
