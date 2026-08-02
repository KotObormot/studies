#include "checkbox.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CheckBox w;

    w.resize(250, 150);
    w.setWindowTitle("QCheckbox started");

    w.show();
    return a.exec();
}
