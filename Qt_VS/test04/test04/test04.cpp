#include "test04.h"
#include "mylabel.h"

test04::test04(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    //创建自定义标签
    mylabel* label = new mylabel(this);

    label->setGeometry(0, 0, 150, 50);
}

test04::~test04()
{}

