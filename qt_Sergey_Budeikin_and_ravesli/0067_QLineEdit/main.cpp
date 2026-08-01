#include "ledit.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Ledit w;

    w.resize(250, 150);
    w.setWindowTitle("QLineEdit");

    w.show();
    return a.exec();
}
