#include "test11.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    test11 window;
    window.show();
    return app.exec();
}
