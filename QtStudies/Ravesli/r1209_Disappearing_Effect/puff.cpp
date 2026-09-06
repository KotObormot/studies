#include <QPainter>
#include <QTimer>
#include <QTextStream>
#include "puff.h"

Puff::Puff(QWidget *parent) : QWidget(parent) {
    // В конструкторе мы запускаем таймер. Каждые 15 мс генерируется событие таймера:
    x = 1;
    opacity = 1.0;
    timerId = startTimer(15);
}

//Puff::~Puff() {}

void Puff::paintEvent([[maybe_unused]] QPaintEvent *e) {
    doPainting();
}

void Puff::doPainting() {

    QPainter painter(this);
    QTextStream out(stdout);

    QString text = "Ravesli.com";

    painter.setPen(QPen(QBrush("#575555"), 1));

    QFont font("Arial", x, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm./*width*/ /*horizontalAdvance*/boundingRect(text).width();

    painter.setFont(font);

    // Если размер шрифта больше 10 точек, то мы постепенно уменьшаем непрозрачность, и текст начинает исчезать:
    if(x > 10) {
        opacity -= 0.01;
        painter.setOpacity(opacity);
    }

    // Если текст полностью исчез, мы останавливаем таймер:
    if(opacity < 0) {
        killTimer(timerId);
        out << "Timer stopped" << Qt::endl;
    }

    int h = height();
    int w = width();

    painter.translate(QPoint(w/2, h/2));
    painter.drawText(-textWidth/2, 0, text);
}

void Puff::timerEvent([[maybe_unused ]] QTimerEvent *e) {
    //Внутри timerEvent() мы увеличиваем размер шрифта и перерисовываем виджет:
    x += 1;
    repaint();
}
