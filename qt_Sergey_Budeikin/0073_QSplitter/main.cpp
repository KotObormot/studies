//#include <QDesktopWidget> In Qt 6, the QDesktopWidget class was completely removed.
#include <QScreen>
#include <QGuiApplication>
#include "splitter.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Splitter w;

    w.resize(350, 300);
    w.setWindowTitle("QSplitter");

    w.show();
    return a.exec();
}
