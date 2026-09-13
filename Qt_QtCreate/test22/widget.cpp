#include "widget.h"
#include "ui_widget.h"

#include <QRegExpValidator>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->pushButton->setEnabled(false);

    //实现使用正则表达式进行验证：
    //1.先创建正则表达
    QRegExp regexp("^1\\d{10}$");
    /*
        ^1 以1开头
        \\d 数字 \\d{10} 10个数字
        $ 结束
    */

    //2.给QLineEdit控件绑定一个校验器
    ui->lineEdit->setValidator(new QRegExpValidator(regexp));

    //3.
    /*
      结论：QRegExpValidator 不是控件
        继承关系一眼区分
            控件 = 继承 QWidget（QLineEdit、QPushButton、QLabel 全是 QWidget 子类，能在界面显示、拖拽）
            QRegExpValidator → 继承 QValidator → 继承 QObject，不继承 QWidget，界面看不见、拖不到 UI 设计师里
       归类：输入校验工具类（数据过滤器），依附 QLineEdit/QSpinBox 等控件工作。
    */

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_lineEdit_textEdited(const QString &arg1)
{
    /*
        ui->lineEdit->validator()：拿到之前绑定在输入框的校验器对象（QValidator 子类，不是控件）
        validate(待校验字符串,光标位置)：校验文本，返回 3 种枚举结果：
        | 返回枚举 | 含义 |
        |------------------------|------------------------------------------|
        |QValidator::Acceptable  |文本完全合法，满足规则                       |
        |QValidator::Intermediate| 内容不完整（比如手机号只输了 5 位，格式半完成） |
        |QValidator::Invalid     | 内容非法（含字母 / 符号等违规字符）           |
    */

    //注意细节：validate 的 第一个参数不能直接传const QString& arg1（接口要求非 const 引用，会触发 const 绑定报错）
    QString contect = arg1;

    int pos = 0;
    if(ui->lineEdit->validator()->validate(contect,pos)==QValidator::Acceptable)
    {
        ui->pushButton->setEnabled(true);
    }
    else
    {
        ui->pushButton->setEnabled(false);
    }

    /*
        validate 和 setValidator 输入拦截的区别
            setValidator(xxx)：打字瞬间拦截非法字符，根本输不进去（硬件级拦截输入）
            validate()：已经输入完成后，校验整段文本，用来控制按钮可用性（业务逻辑校验）
    */
}








