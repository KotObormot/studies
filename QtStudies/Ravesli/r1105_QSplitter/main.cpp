// #include <QDeskTopWidget> // <QDesktopWidget> был полностью удален из библиотеки.
// Для работы с экранами, их размерами и геометрией теперь нужно использовать класс QScreen совместно с QGuiApplication. [Qt6.md]
#include <QGuiApplication>
#include <QScreen>
#include "splitter.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Splitter w;

    w.resize(350, 300);
    w.setWindowTitle("QSplitter");

    w.show();
    return a.exec();
}
