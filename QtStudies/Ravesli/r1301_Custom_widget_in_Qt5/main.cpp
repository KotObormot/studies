#include "burning.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Burning w;

    w.resize(370, 200);
    w.setWindowTitle("The Burning Widget");

    w.show();
    return a.exec();
}
