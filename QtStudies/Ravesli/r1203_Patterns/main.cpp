#include "patterns.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Patterns w;

    w.resize(350,280);
    w.setWindowTitle("Patterns");

    w.show();
    return a.exec();
}
