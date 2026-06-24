#pragma execution_character_set("utf-8")
// 应用核心
#include <QtWidgets/QApplication>
// 基础窗口
#include <QtWidgets/QWidget>
// 水平布局
#include <QtWidgets/QHBoxLayout>
// 垂直布局
#include <QtWidgets/QVBoxLayout>
// 按钮控件
#include <QtWidgets/QPushButton>
// 标签文本
#include <QtWidgets/QLabel>
// 容器边框面板
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>

// 基础核心模块
#include <QtCore/QString>
#include <QtCore/QSize>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    // 1. 顶层窗口
    QWidget w;
    w.setWindowTitle("setContentsMargins 演示Demo");
    w.resize(700, 500);
    w.setStyleSheet("background:#f0f0f0;");

    // 2. 创建水平布局
    QHBoxLayout* layout = new QHBoxLayout(&w);

    // ========== 核心：修改这里的4个数字看效果 ==========
    // 参数：左、上、右、下 单位px
    layout->setContentsMargins(0, 0, 0, 0); //简单的说就是：布局框的距离窗口：左、上、右、下的距离

    // 控件之间默认间隙
    layout->setSpacing(0); // 默认在水平布局中的两个按钮是之间是有间隙的

    // 3. 添加两个按钮做对比
    QPushButton* btn1 = new QPushButton("按钮1");
    btn1->setStyleSheet("background:#77aaff;");

    QPushButton* btn2 = new QPushButton("按钮2");
    btn2->setStyleSheet("background:#ffaa77;");

    layout->addWidget(btn1);
    layout->addWidget(btn2);

    w.show();
    return a.exec();
}
