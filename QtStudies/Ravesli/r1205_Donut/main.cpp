#include "donat.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Donat w;

    w.resize(350, 280);
    w.setWindowTitle("Donut");

    w.show();
    return a.exec();
}
