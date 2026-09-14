#include "test05.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    test05 window;
    window.show();
    return app.exec();
}
