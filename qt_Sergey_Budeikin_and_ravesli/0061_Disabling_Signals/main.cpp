#include "disconnect.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Disconnect w;

    w.resize(250, 150);
    w.setWindowTitle("Disconnect");

    w.show();
    return a.exec();
}
