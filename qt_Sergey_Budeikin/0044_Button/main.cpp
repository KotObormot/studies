#include "mybutton.h"

//#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyButton window;

    window.resize(350, 250);
    window.setWindowTitle("QPushButton");

    window.show();
    return a.exec();
}
