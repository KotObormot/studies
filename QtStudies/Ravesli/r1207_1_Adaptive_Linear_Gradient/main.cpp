#include "adaptivelineargradient.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AdaptiveLinearGradient w;
    w.resize(350, 260);
    w.setWindowTitle("The Linear Gradient");
    w.show();
    return a.exec();
}
