#include "absolute.h"

//#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Absolute window;

    window.setWindowTitle("Absolute");

    window.show();
    return a.exec();
}
