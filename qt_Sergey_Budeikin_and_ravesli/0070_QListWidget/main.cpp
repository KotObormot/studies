#include "listwidget.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ListWidget w;

    w.setWindowTitle("QListWidget");

    w.show();
    return a.exec();
}
