#include "test01.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    test01 window;
    window.show();
    return app.exec();
}
