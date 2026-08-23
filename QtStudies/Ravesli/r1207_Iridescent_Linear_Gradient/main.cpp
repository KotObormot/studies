#include "iridescentlingrad.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IridescentLinGrad w;

    w.resize(600, 500);
    w.setWindowTitle("Iridescent Linear Gradient");

    w.show();
    return a.exec();
}
