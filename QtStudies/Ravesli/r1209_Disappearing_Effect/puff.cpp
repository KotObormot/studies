#include <QPainter>
#include <QTimer>
#include <QTextStream>
#include "puff.h"

Puff::Puff(QWidget *parent) : QWidget(parent) {
    x = 1;
    opacity = 1.0;
    timerId = startTimer(15);
}

void Puff::paintEvent([[maybe_unused]] QPaintEvent *e) {
    doPainting();
}

void Puff::doPainting() {
    QPainter painter(this);

    QString text = "Ravesli.com";
    painter.setPen(QPen(QBrush("#575555"), 1));

    QFont font("Arial", x, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.boundingRect(text).width();

    painter.setFont(font);

    // Только устанавливаем прозрачность (изменение логики отсюда убрали)
    if (x > 10) {
        painter.setOpacity(opacity);
    }

    int h = height();
    int w = width();

    painter.translate(QPoint(w/2, h/2));
    painter.drawText(-textWidth/2, 0, text);
}

void Puff::timerEvent([[maybe_unused]] QTimerEvent *e) {
    QTextStream out(stdout);

    // 1. Увеличиваем размер шрифта
    x += 1;

    // 2. Если нужно, уменьшаем прозрачность
    if (x > 10) {
        opacity -= 0.01;
    }

    // 3. ПРОВЕРКА: Если текст исчез, останавливаем таймер здесь
    if (opacity < 0) {
        if (timerId != -1) {
            killTimer(timerId);
            timerId = -1; // Сбрасываем ID, чтобы гарантировать, что больше не вызовем killTimer
            out << "Timer stopped" << Qt::endl;
        }
        return; // Больше не нужно перерисовывать
    }

    // Вместо repaint() в Qt принято использовать update() — это работает плавнее и безопаснее
    update();
}
