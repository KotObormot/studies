#include "anothermenu.h"

//#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AnotherMenu w;
    w.resize(450, 350);
    w.setWindowTitle("Another Menu");
    w.show();
    return a.exec();
}
