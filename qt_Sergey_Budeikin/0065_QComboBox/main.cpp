#include "combodoxex.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ComboDoxEx w;

    w.resize(300, 150);
    w.setWindowTitle("Combobox");
    w.show();
    return a.exec();
}
