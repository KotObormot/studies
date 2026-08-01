#include "click.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Click w;

    w.resize(250, 150);
    w.setWindowTitle("Quit");

    w.show();
    return a.exec();
}
