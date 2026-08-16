#include "lineargradients.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LinearGradients w;

    w.resize(350, 640);
    w.setWindowTitle("Linear Gradients");

    w.show();
    return a.exec();
}
