#include <QPainter>
#include "donat.h"

Donat::Donat(QWidget *parent) : QWidget(parent) {}

Donat::~Donat() {}

void Donat::paintEvent([[maybe_unused]] QPaintEvent *e) {

    doPainting();
}

void Donat::doPainting() {

    QPainter painter(this);

    //painter.setPen(QPen(QBrush("#535353"), 0.5));
    painter.setPen(QPen(QBrush("red"), 0.5));
    // Включим сглаживание, чтобы рендеринг нашего пончика был более качественным:
    painter.setRenderHint(QPainter::Antialiasing);

    // При помощи данных линий, для облегчения процесса отрисовки нашей фигуры пончика, мы переместим начало системы координат в середину окна.
    // По умолчанию оно расположено в верхнем левом углу окна (данная точка имеет координаты (0;0)):
    int h = height();
    int w = width();

    painter.translate(QPoint(w/2, h/2));

    // В цикле for мы по очереди рисуем 72 вращаемых эллипса, при этом каждый последующий эллипс поворачивается на заданный угол относительно предыдущего:
    for(qreal rot = 0; rot < 360.0; rot += 5.0) {
        painter.drawEllipse(-125, -40, 250, 80);
        painter.rotate(5.0);
    }
}
