#include "checkbox.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    CheckBox w;

    w.resize(300, 200);
    w.setWindowTitle("QCheckBox start");

    w.show();
    return a.exec();
}
