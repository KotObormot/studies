#include "widgetmoveevent.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WidgetMoveEvent w;

    w.resize(250, 150);
    //w.setWindowTitle("Move");
    w.move(300, 300);

    w.show();
    return a.exec();
}
