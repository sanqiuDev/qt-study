#include "test03.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    test03 window;
    window.show();
    return app.exec();
}
