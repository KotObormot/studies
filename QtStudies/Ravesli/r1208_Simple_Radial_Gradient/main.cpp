#include "radialgradient.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RadialGradient w;

    w.resize(600, 500);
    w.setWindowTitle("Radial Gradient");

    w.show();
    return a.exec();
}
