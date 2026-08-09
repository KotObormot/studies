#include <QPainter>
#include <QPainterPath>
#include "shapes.h"

Shapes::Shapes(QWidget *parent) : QWidget(parent) {}

Shapes::~Shapes() {}

void Shapes::paintEvent([[maybe_unused]] QPaintEvent *e) {
    doPainting();
}

void Shapes::doPainting() {

    QPainter *painter = new QPainter(this);

    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(QPen(QBrush("white"), 1));
    painter->setBrush(QBrush(QColor("purple")));

    // QPainterPath — это класс, используемый для создания более сложных фигур при помощи заданной траектории рисования.
    // С его помощью мы будем создавать так называемые «кривые Безье (Bézier)»
    QPainterPath pathBézier;

    pathBézier.moveTo(5, 5);
    pathBézier.cubicTo(40, 5,  50, 50,  99, 99);
    pathBézier.cubicTo(5, 99,  50, 50,  5, 5);
    painter->drawPath(pathBézier);

    //Данные строки кода рисуют сектор круга, хорду и прямоугольник с закругленными углами:
    painter->drawPie(130, 20, 90, 60, 30*16, 120*16);
    painter->drawChord(240, 30, 90, 60, 0, 16*180);
    //painter->drawRoundedRect(20, 120, 80, 50);
    painter->drawRoundedRect(20, 120, 80, 50, 10.0, 10.0);

    // с помощью метода drawPolygon(), мы рисуем полигон, состоящий из пяти точек:
    QPolygon polygon({QPoint(130, 140), QPoint(180, 170), QPoint(180, 140)
                      , QPoint(220, 110), QPoint(140, 100)});
    painter->drawPolygon(polygon);

    //Возможности Qt5 позволяют создать траекторию рисования на основе символа, написанного с использованием заданного шрифта:
    QPointF baseline(20, 250);
    QFont font("Georgia", 55);
    QPainterPath pathQ;
    pathQ.addText(baseline, font, "Q");
    painter->drawPath(pathQ);

    // Так как окружность является частным случаем эллипса, то мы можем нарисовать обе эти фигуры при помощи одного и того же метода DrawEllipse().
    //Параметрами данного метода являются координаты начала (x;y) ограничивающего эллипс прямоугольника, а также ширина этого прямоугольника и его высота:
    painter->drawEllipse(140, 200, 60, 60);
    painter->drawEllipse(240, 200, 90, 60);
}
