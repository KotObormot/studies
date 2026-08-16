#include "lingrad.h"

LinGrad::LinGrad(QWidget *parent) : QWidget(parent) {

    // Переводим градиент в режим относительных координат объекта
    m_gradVer.setCoordinateMode(QGradient::ObjectMode);
    // Теперь (0, 0) — это левый верхний угол прямоугольника, а (0, 1) — левый нижний.

    // Градиент пойдет строго сверху вниз по всей высоте закрашиваемой области.
    m_gradVer.setStart(0.0, 0.0);
    m_gradVer.setFinalStop(0.0, 1.0);

    m_gradVer.setColorAt(0.0, Qt::darkGreen);
    m_gradVer.setColorAt(0.5, Qt::yellow);
    m_gradVer.setColorAt(1.0, Qt::darkMagenta);
}

//LinGrad::~LinGrad() {}

void LinGrad::paintEvent([[maybe_unused]] QPaintEvent *e) {
    QPainter painter(this);

    // Закрашиваем весь виджет целиком от угла до угла.
    // Градиент сам растянется по вертикали на всю текущую высоту окна.
    //painter.fillRect(50, 50, this->width() - 50, this->height() - 50, m_gradVer);

    painter.setBrush(m_gradVer);
    painter.drawRect(20, 20, this->width() - 20, this->height() - 20);
}
