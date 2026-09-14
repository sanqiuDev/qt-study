#include "test02.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    test02 window;
    window.show();
    return app.exec();
}
