#include <QPainter>
#include "lines.h"

Lines::Lines(QWidget *parent) : QWidget(parent) {}

Lines::~Lines() {}

void Lines::paintEvent(QPaintEvent *e) {
    // Т.к. метод paintEvent() вызывается каждый раз при обновлении виджета, то мы будем создавать объект класса QPainter
    //и выполнять операцию рисования внутри данного метода.
    // Поскольку сам объект QPaintEvent *e не используется, то желательно заранее сообщить об этом с помощью макроса Q_UNUSED,
    // иначе компилятор выдаст предупреждение.

    Q_UNUSED(e);

    QPainter qp(this);
    drawLines(&qp);
}

// Фактическая отрисовка линии делегируется методу drawLines():
void Lines::drawLines(QPainter *qp) {

    // При помощи класса QPen мы создаем объект pen со следующими параметрами:
    //      черный цвет;
    //      толщина 2 пикселя;
    //      сплошная заливка.
    // Объект pen используется для рисования линий и контуров фигур. Устанавливаем его с помощью метода setPen():
    QPen pen(Qt::white, 2, Qt::SolidLine);
    qp->setPen(pen);
    //Метод drawLine() рисует линию, его четыре параметра — это координаты двух точек (начала и конца линии):
    qp->drawLine(20, 40, 250, 235);

    //Метод setStyle() устанавливает стиль Qt::DashLine (пунктирная линия) для объекта pen:
    pen.setStyle(Qt::DashLine);
    qp->setPen(pen);
    qp->drawLine(20, 80, 250, 80);

    pen.setStyle(Qt::DashDotLine);
    qp->setPen(pen);
    qp->drawLine(20, 120, 250, 120);

    pen.setStyle(Qt::DotLine);
    qp->setPen(pen);
    qp->drawLine(20, 160, 250, 160);

    pen.setStyle(Qt::DashDotDotLine);
    qp->setPen(pen);
    qp->drawLine(20, 200, 250, 200);

    QVector<qreal> dashes;
    qreal space = 4;

    dashes << 1 << space << 4 << space;

    pen.setStyle(Qt::CustomDashLine);
    pen.setDashPattern(dashes);

    qp->setPen(pen);
    qp->drawLine(20, 240, 250, 45);
}
