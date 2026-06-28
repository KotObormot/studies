#include "formex.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FormEx w;

    w.setWindowTitle("Form example");

    w.show();
    return a.exec();
}
