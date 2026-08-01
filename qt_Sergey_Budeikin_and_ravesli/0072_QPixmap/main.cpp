#include "pixmap.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Pixmap w;

    // w.resize(250, 150);
    w.setWindowTitle("QPixMap");

    w.show();
    return a.exec();
}
