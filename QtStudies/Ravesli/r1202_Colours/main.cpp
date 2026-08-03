#include "colours.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Colours w;

    w.resize(360, 280);
    w.setWindowTitle("Colours");

    w.show();
    return a.exec();
}
