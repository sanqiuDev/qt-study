#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建半模态对话框

    //1.一键创建菜单并将其添加到（主窗口自带菜单栏）中
    QMenu *menu = menuBar()->addMenu("菜单1");
    /*
        // 重载1：参数是现成QMenu*，返回QAction*
        QAction* addMenu(QMenu *menu);

        // 重载2：参数是QString标题，返回新建的QMenu*
        QMenu* addMenu(const QString &title);
        传入字符串时，函数内部自动 new QMenu ("文件 (&F)")，生成菜单对象，把这个新菜单装入菜单栏，
        最后把这个新QMenu指针返回给menuFile变量
    */

    //2.创建菜单项
    QAction *action = new QAction("菜单项1",this);

    //3.将菜单项目添加到菜单中
    menu->addAction(action);


    //4.进行信号和槽函数的关联
    connect(action,&QAction::triggered,this,
            [=]()
    {
        //第一步：在堆上创建对话框
        QDialog *dialog = new QDialog();

        //第二步：设置自动释放的属性
        dialog->setAttribute(Qt::WA_DeleteOnClose);

        //第三步：设置模态窗口
        dialog->setModal(true);
        /*
            设置为模态窗口：弹窗弹出后，父窗口锁定无法点击，效果等价exec()，但不用阻塞代码。
            区别：exec()阻塞代码停在当前行；setModal(true)+show()代码继续运行，仅界面锁定父窗口。
        */

        //第四步：非模态启动函数
        dialog->show();


        //验证：代码是否还能继续执行：
        dialog->setWindowTitle("创建（半模态）对话框");
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //创建（非模态）对话框
    //1.堆上创建对话框
    QDialog *dialog1 = new QDialog(this);

    //2.设置自动释放属性
    dialog1->setAttribute(Qt::WA_DeleteOnClose);

    //其他
//    dialog1->setWindowTitle("创建（非模态）对话框");    //窗口标题
    dialog1->resize(500,400);                        //窗口尺寸

    //3.非模态调用
    dialog1->show();


    //验证：代码是否还能继续执行：
    dialog1->setWindowTitle("创建（非模态）对话框");    //窗口标题
}


void MainWindow::on_pushButton_2_clicked()
{
    //创建（模态）对话框
    //1.栈/堆上创建对话框
    QDialog dialog2;

    //其他
//    dialog2.setWindowTitle("创建（模态）对话框");    //窗口标题
    //这里一定要注意一个细节就是：
    //→ 栈实例（普通变量，不是指针）

    //2.模态调用
    dialog2.exec();

    //验证：代码是否还能继续执行：
    dialog2.setWindowTitle("创建（模态）对话框");    //窗口标题
}
