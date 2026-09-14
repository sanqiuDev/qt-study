#include "test04.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    test04 window;
    window.show();
    return app.exec();
}
