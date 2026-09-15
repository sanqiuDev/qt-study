#include "test09.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    test09 window;
    window.show();
    return app.exec();
}
