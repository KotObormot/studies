#include "lines.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Lines w;

    w.resize(280, 270);
    w.setWindowTitle("QPainter / Lines");
    w.show();
    return a.exec();
}
