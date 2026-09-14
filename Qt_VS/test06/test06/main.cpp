#include "test06.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    test06 window;
    window.show();
    return app.exec();
}
