#include "checkable.h"

//#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Checkable w;

    w.resize(850, 750);
    w.setWindowTitle("Checkable menu");
    w.show();

    return a.exec();
}
