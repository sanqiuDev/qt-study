#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //1.设置根节点的名字
    ui->treeWidget->setColumnCount(2);  // 设置2列
    ui->treeWidget->setHeaderLabels(QStringList() << "动物" << "品种");

    //2.设置顶层节点
    //第一步：创建单元格对象
    QTreeWidgetItem *item1 = new QTreeWidgetItem();
    //第二步：设置单元格的文本项
    item1->setText(0,"猫");     //第一列
    /*
        void setText(int column, const QString &text);
            column：列的索引（从 0 开始）
            text：要设置的文本内容
    */
    //第三步：添加到顶层节点中
    ui->treeWidget->addTopLevelItem(item1);

    //3.设置子节点
    QTreeWidgetItem *item2 = new QTreeWidgetItem();
    item2->setText(0,"加菲猫");
    item2->setText(1,"红虎斑异国短毛猫");
    item1->addChild(item2);

    QTreeWidgetItem *item3 = new QTreeWidgetItem();
    item3->setText(0,"罗小黑");
    item3->setText(1,"中华田园猫·玄猫");
    item1->addChild(item3);



    //再来新增一个顶层节点
    QTreeWidgetItem *item4 = new QTreeWidgetItem();
    item4->setText(0,"狗");
    ui->treeWidget->addTopLevelItem(item4);

    //再搞一点子节点
    QTreeWidgetItem *item5 = new QTreeWidgetItem();
    item5->setText(0,"欧迪");
    item5->setText(1,"腊肠犬");
    item4->addChild(item5);

    QTreeWidgetItem *item6 = new QTreeWidgetItem();
    item6->setText(0,"丹丹");
    item6->setText(1,"墨西哥无毛犬");
    item4->addChild(item6);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_addTop_clicked()
{
    //1.
    QString str = ui->lineEdit->text();

    //2.
    QTreeWidgetItem *item = new QTreeWidgetItem();
    /*
        setHeaderLabels (带 s) → 一次性设置一整行 / 一整列的多个表头
            // 设置水平表头（一次设置3列表头）
            ui->tableWidget->setHorizontalHeaderLabels({"姓名", "年龄", "性别"});
        setHeaderLabel (不带 s) → 只设置单个表头（当前这一个）
            // 只设置第0列表头
            header->setHeaderLabel("姓名");
    */

    //3.
    item->setText(0,str);
     ui->treeWidget->addTopLevelItem(item);
}

void Widget::on_pushButton_addSelect_clicked()
{
    //第一步：准备顶层元素
    QTreeWidgetItem *currItem = ui->treeWidget->currentItem();
    if(currItem==nullptr) return ;


    //第二步：准备新创建子元素
    //1.准备
    QString str = ui->lineEdit->text();
    //2.
    QTreeWidgetItem *newItem = new QTreeWidgetItem();
    //3.设置
    currItem->setText(0,str);


    //第三步：两者绑定
    currItem->addChild(newItem);

}

void Widget::on_pushButton_deleteSelect_clicked()
{
    //第一步：获取要删除的选中的元素
    QTreeWidgetItem *currItem = ui->treeWidget->currentItem();
    if(currItem==nullptr) return ;

    //第二步：获得要删除元素的父类
    QTreeWidgetItem *parentItem = currItem->parent();

    //情况一：要删除的控件是顶层元素
    if(parentItem==nullptr)
    {
        int index = ui->treeWidget->indexOfTopLevelItem(currItem);
        ui->treeWidget->takeTopLevelItem(index);
    }
    /*
        1. indexOfTopLevelItem(QTreeWidgetItem *item)
            作用：查找顶层根节点在所有顶层条目1数组中的序号
            返回值：int，从 0 开始索引；如果item不是顶层节点，返回 -1
            适用：只对没有父节点的一级条目生效，子节点不能用这个函数

        2. takeTopLevelItem(int index)参数：顶层条目的索引
            效果：树形界面上删除这条顶层项，把条目对象从 Tree 剥离出来，函数返回 QTreeWidgetItem
            ⚠️ 不会自动 delete 释放堆内存，需要手动delete释放：
    */

    //情况二：要删除的控件是子元素
    else
    {
        parentItem->removeChild(currItem);
    }
}

















