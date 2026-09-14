#include "test07.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    test07 window;
    window.show();
    return app.exec();
}
