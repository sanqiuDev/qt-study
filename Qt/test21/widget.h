#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
//
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void compare();

private slots:
    void on_password_textEdited(const QString &arg1);

    void on_password_again_textEdited(const QString &arg1);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
