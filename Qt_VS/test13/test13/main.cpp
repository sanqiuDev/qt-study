#include "test13.h"
#include <QtWidgets/QApplication>

#include <QDir>
#include <QList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    test13 window;



    window.show();
    return app.exec();
}
