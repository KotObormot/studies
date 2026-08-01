#include "label.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Label w;

    w.setWindowTitle("QLabel");

    w.show();
    return a.exec();
}
