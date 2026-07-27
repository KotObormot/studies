#include "progressbarex.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ProgressBarEx w;

    w.resize(250, 150);
    w.setWindowTitle("QProgressBar");

    w.show();
    return a.exec();
}
