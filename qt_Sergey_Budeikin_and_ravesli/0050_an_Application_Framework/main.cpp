#include "skeleton.h"

//#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Skeleton w;

    w.resize(750, 550);
    w.setWindowTitle("Application framework / skeleton");

    w.show();
    return a.exec();
}
