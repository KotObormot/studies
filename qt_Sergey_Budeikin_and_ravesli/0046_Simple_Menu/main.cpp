#include "simplemenu.h"

//#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SimpleMenu window;

    window.resize(350, 250);
    window.setWindowTitle("Simple menu");

    window.show();
    return a.exec();
}
