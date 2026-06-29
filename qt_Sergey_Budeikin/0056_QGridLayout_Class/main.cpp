#include "calculator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculator w;

    w.move(300, 300);
    //w.resize(300, 300);
    w.setWindowTitle("Calculator");

    w.show();
    return a.exec();
}
