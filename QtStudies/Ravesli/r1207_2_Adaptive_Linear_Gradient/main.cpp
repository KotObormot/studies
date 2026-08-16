#include "lingrad.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LinGrad w;

    w.resize(350, 260);
    w.setWindowTitle("The Adaptive Linear Gradient");

    w.show();
    return a.exec();
}
