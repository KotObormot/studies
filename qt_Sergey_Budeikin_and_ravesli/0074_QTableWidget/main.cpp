#include "table.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Table w;

    w.resize(400, 250);
    w.setWindowTitle("QTableWidget");

    w.show();
    return a.exec();
}
