#include <QApplication>
#include <QPainter>
#include <QPainterPath>
#include "transparentrectangles.h"

TransparentRectangles::TransparentRectangles(QWidget *parent) : QWidget(parent) {}

TransparentRectangles::~TransparentRectangles() {}

void TransparentRectangles::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e);

    doPainting();
}

void TransparentRectangles::doPainting() {

    QPainter painter(this);

    for (int i=1; i<=11; i++) {
        // Метод setOpacity() устанавливает непрозрачность для объекта painter класса QPainter.
        // Данное значение должно находиться в диапазоне от 0.0 до 1.0, где 0.0 — это абсолютная прозрачность, а 1.0 — абсолютная непрозрачность:
        painter.setOpacity(i*0.1);
        painter.fillRect(50*i, 20, 40, 40, Qt::darkGray);
    }
}
