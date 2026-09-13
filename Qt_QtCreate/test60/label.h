#ifndef LABEL_H
#define LABEL_H

#include <QLabel>
#include <QDebug>
#include <QMouseEvent>

class Label : public QLabel
{
public:
//    Label();
    Label(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void mouseDoubleClickEvent(QMouseEvent *event);


    void mouseMoveEvent(QMouseEvent *ev);
};

#endif // LABEL_H
