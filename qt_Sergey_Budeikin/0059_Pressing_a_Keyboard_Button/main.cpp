#include "keypress.h"

//#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KeyPress w;

    w.resize(250, 150);
    w.setWindowTitle("Key press");

    w.show();
    return a.exec();
}
