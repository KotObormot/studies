#include "timer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Timer w;

    w.resize(350, 250);
    w.setWindowTitle("Timer");

    w.show();
    return a.exec();
}
