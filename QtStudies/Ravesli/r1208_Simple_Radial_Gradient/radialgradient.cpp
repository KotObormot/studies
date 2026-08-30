#include "radialgradient.h"

RadialGradient::RadialGradient(QWidget *parent) : QWidget(parent) {

    int h = height();
    int w = width();

    m_gradRad.setCenter(h/2, w/2);
    m_gradRad.setFocalPoint(h/2, w/2);
    m_gradRad.setRadius(180);

    m_gradRad.setColorAt(0, QColor("#032E91"));
    m_gradRad.setColorAt(0.3, Qt::white);
    m_gradRad.setColorAt(1, QColor("#032E91"));
}

//RadialGradient::~RadialGradient() {}

void RadialGradient::paintEvent([[maybe_unused]] QPaintEvent *e) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(0, 0, this->width(), this->height(), m_gradRad);
}
