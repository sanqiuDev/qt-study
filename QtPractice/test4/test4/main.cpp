#include "test4.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    test4 window;
    window.show();
    return app.exec();
}
