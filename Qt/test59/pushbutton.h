#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QPushButton>
#include <QWidget>

class PushButton : public QPushButton
{
    Q_OBJECT
public:
//    PushButton();
    PushButton(QWidget *parent);

    void enterEvent(QEvent *event);
};

#endif // PUSHBUTTON_H
