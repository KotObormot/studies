#include "verticalbox.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VerticalBox w;

    w.resize(240, 230);
    w.setWindowTitle("Vertical Box");

    w.show();
    return a.exec();
}
