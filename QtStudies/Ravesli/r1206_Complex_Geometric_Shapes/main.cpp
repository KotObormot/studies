#include "shapes.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Shapes w;

    w.resize(350, 280);
    w.setWindowTitle("Shapes");

    w.show();
    return a.exec();
}
