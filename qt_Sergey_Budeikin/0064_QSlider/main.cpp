#include "slider.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Slider w;

    w.setWindowTitle("Slider");

    w.show();
    return a.exec();
}
