#ifndef LABEL_H
#define LABEL_H

#include <QLabel>
#include <QWidget>

class Label : public QLabel
{
    Q_OBJECT
public:
    //Label();                  默认生成的
    Label(QWidget *parent);   //这里需要写成


    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
};

#endif // LABEL_H
