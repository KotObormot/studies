#include "spinbox.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SpinBox w;

    w.resize(250, 150);
    w.setWindowTitle("QSpinBox");

    w.show();
    return a.exec();
}
