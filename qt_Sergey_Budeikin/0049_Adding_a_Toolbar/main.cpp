#include "toolbar.h"

//#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Toolbar w;

    w.resize(650, 550);
    w.setWindowTitle("QToolBar");

    w.show();
    return a.exec();
}
