#pragma execution_character_set("utf-8")

#include <QCoreApplication>
#include <QTextCodec>
#include <QDebug>
#include <QMap>
#include <QPixmap>
#include <QVector>
#include <QMessageBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QByteArray>
#include <QDateTime>
#include <QWidget>

#include "QtSingleApplication.h"

// ========== 1. 注册自定义 MetaType (跨线程传递前必须注册) ==========
void registerMetaTypes() 
{
    qRegisterMetaType<QMap<int, QString>>("QMap<int,QString>");
    qRegisterMetaType<QPixmap>("QPixmap");
    qRegisterMetaType<QVector<double>>("QVector<double>");
    qDebug() << "[MetaType] 注册完成";
}

// ========== 2. 演示 qputenv / qgetenv ==========
void demoEnvironment() 
{
    // 设置环境变量
    qputenv("MY_APP_MODE", "demo");
    qputenv("MY_APP_DEBUG", "1");

    // 读取环境变量
    QByteArray mode  = qgetenv("MY_APP_MODE");
    QByteArray debug = qgetenv("MY_APP_DEBUG");
    QByteArray path  = qgetenv("PATH");

    qDebug() << "[qputenv/qgetenv]"
             << "MY_APP_MODE =" << mode
             << "MY_APP_DEBUG =" << debug
             << "PATH 长度:" << path.length();
}

int main(int argc, char *argv[])
{
    // ========== 3. 在 QApplication 构造前设置全局属性 ==========
    // AA_DisableHighDpiScaling: 禁用高DPI缩放
    QCoreApplication::setAttribute(Qt::AA_DisableHighDpiScaling, true);
    // AA_UseOpenGLES: 强制使用 OpenGL ES
    QCoreApplication::setAttribute(Qt::AA_UseOpenGLES, true);
    // AA_ShareOpenGLContexts: 共享 OpenGL 上下文
    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts, true);

    // ========== 4. 设置本地编码 ==========
    // QTextCodec::setCodecForLocale 影响文件读写等操作的默认编码
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    qDebug() << "[TextCodec] 当前编码:" << QTextCodec::codecForLocale()->name();

    // ========== 5. 环境变量 & MetaType ==========
    demoEnvironment();
    registerMetaTypes();

    // ========== 6. 构建单实例应用 ==========
    // QtSingleApplication: 通过 QSharedMemory 检测是否已有实例在运行
    SharedTools::QtSingleApplication app("MyDemoApp_6_24_7day", argc, argv);

    if (app.isRunning()) 
    {
        // 已有实例在跑, 发送消息后退出
        QString msg = "新实例启动，参数: ";
        for (int i = 1; i < argc; ++i) {
            msg += QString(argv[i]) + " ";
        }
        bool ok = app.sendMessage(msg);
        qDebug() << "[QtSingleApplication] 已有实例在运行，发送消息"
                 << (ok ? "成功" : "失败");
        return 0;
    }

    // 第一个实例: 创建窗口
    QWidget w;
    w.setWindowTitle("Qt 综合功能学习 Demo");
    w.resize(1000, 500);

    QVBoxLayout* lay = new QVBoxLayout(&w);

    // 系统信息展示
    QString info = QString(
        "系统信息:\n"
        "  编码: %1\n"
        "  AA_DisableHighDpiScaling: %2\n"
        "  AA_UseOpenGLES: %3\n"
        "  AA_ShareOpenGLContexts: %4\n"
        "  环境变量 MY_APP_MODE: %5"
    ).arg(QString(QTextCodec::codecForLocale()->name()))
     .arg(QCoreApplication::testAttribute(Qt::AA_DisableHighDpiScaling) ? "启用" : "禁用")
     .arg(QCoreApplication::testAttribute(Qt::AA_UseOpenGLES) ? "启用" : "禁用")
     .arg(QCoreApplication::testAttribute(Qt::AA_ShareOpenGLContexts) ? "启用" : "禁用")
     .arg(QString(qgetenv("MY_APP_MODE")));

    QLabel* infoLabel = new QLabel(info);
    infoLabel->setWordWrap(true);
    lay->addWidget(infoLabel);

    // 消息接收显示区
    QLabel* msgLabel = new QLabel("等待其他实例的消息...");
    msgLabel->setStyleSheet("background:#f5f5f5;padding:10px;border:1px solid #ccc;");
    msgLabel->setWordWrap(true);
    msgLabel->setMinimumHeight(60);
    lay->addWidget(msgLabel);

    // 消息输入框
    QLineEdit* input = new QLineEdit;
    input->setPlaceholderText("输入要发送给其他实例的消息...");
    lay->addWidget(input);

    // 发送消息按钮
    QPushButton* sendBtn = new QPushButton("向其他实例发送消息");
    lay->addWidget(sendBtn);

    // 测试 MetaType 按钮
    QPushButton* metaBtn = new QPushButton("测试已注册的 MetaType");
    lay->addWidget(metaBtn);

    // ========== 7. 信号连接 ==========
    // 接收其他实例发来的消息
    QObject::connect(&app, &SharedTools::QtSingleApplication::messageReceived,
        [msgLabel](const QString& msg) {
            msgLabel->setText(QString("收到消息 [%1]:\n%2")
                .arg(QDateTime::currentDateTime().toString("HH:mm:ss"))
                .arg(msg));
        });

    // 发送消息给其他实例
    QObject::connect(sendBtn, &QPushButton::clicked, [&]() {
        QString text = input->text().trimmed();
        if (text.isEmpty())
        {
            text = "Hello from first instance!";
        }

        bool sent = app.sendMessage(text);
        msgLabel->setText(sent
            ? QString("已发送:\n%1").arg(text)
            : "发送失败（当前没有其他实例）");
    });

    // 测试已注册的 MetaType
    QObject::connect(metaBtn, &QPushButton::clicked, [&w]() {
        QMap<int, QString> map;
        map[0] = "零"; map[1] = "壹"; map[2] = "贰";

        QVector<double> vec = { 3.14, 2.718, 1.414, 0.577 };

        QPixmap pix(80, 80);
        pix.fill(QColor(100, 150, 200));

        QMessageBox::information(&w, "MetaType 测试",
            QString("QMap<int,QString> : %1 项\n"
                    "QVector<double>   : %2 项\n"
                    "QPixmap           : %3 x %4")
            .arg(map.size()).arg(vec.size())
            .arg(pix.width()).arg(pix.height()));
    });

    w.show();
    qDebug() << "[Demo] 应用已启动，PID:" << QCoreApplication::applicationPid();
    return app.exec();
}