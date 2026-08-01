#include "plusminus.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    PlusMinus window;

    window.resize(300, 300);
    window.setWindowTitle("Plus Minus");

    window.show();
    return a.exec();
}
