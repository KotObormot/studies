#include "statusbar.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    StatusBar w;

    w.resize(300, 200);
    w.setWindowTitle("QStatusBar");

    w.show();
    return a.exec();
}
