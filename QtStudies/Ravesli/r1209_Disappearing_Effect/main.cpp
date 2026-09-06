#include "puff.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Puff w;

    w.resize(650, 580);
    w.setWindowTitle("Puff");

    w.show();
    return a.exec();
}
