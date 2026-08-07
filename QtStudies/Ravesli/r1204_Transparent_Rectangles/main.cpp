#include "transparentrectangles.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TransparentRectangles w;

    w.resize(630, 90);
    w.setWindowTitle("Transparent rectangles");

    w.show();
    return a.exec();
}
