#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTextEdit>
class Dialog : public QDialog
{
    Q_OBJECT
    void handle();

public:
    Dialog();

    QTextEdit *textEdit;
};

#endif // DIALOG_H
