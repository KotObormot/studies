#include <QPainter>
#include "patterns.h"

Patterns::Patterns(QWidget *parent) : QWidget(parent) {}

Patterns::~Patterns() {}

void Patterns::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);

    doPainting();
}

void Patterns::doPainting() {

    QPainter painter(this);
    //painter.setPen(Qt::NoPen);
    painter.setPen(QColor("#ff0000"));      // red color of the frame

    // Создаем прямоугольник с определенным рисунком.
    // Qt::HorPattern — это константа, используемая для создания шаблона горизонтальных линий:
    //painter.setBrush(Qt::HorPattern);
    // как переписать код, чтобы в нарисованном прямогульнике был узор на фоне белого цвета?Qt6
    //painter.setBrush(QBrush("#ffffff"));    // white
    // В вашем текущем коде вторая строка просто полностью перезаписывает первую.

    // Чтобы внутри прямоугольника одновременно отображался узор и белый цвет фона, вам нужно настроить оба свойства в одном объекте QBrush.
    // Var. 1:
    /*QBrush brush(QColor("#ffffff"), Qt::HorPattern);    // Конструктор QBrush: Принимает сразу два параметра — цвет (QColor) и стиль заполнения (Qt::BrushStyle).
    painter.setBrush(brush);    // Цвет самого узора (линий) в данном случае будет браться из текущего пера painter.pen().
    */

    // Var. 2
    // Если вы хотите полностью контролировать цвет линий узора и цвет фона под узором, можно использовать альтернативный вариант с настройкой палитры brush:
    QBrush brush(Qt::HorPattern);
    brush.setColor(Qt::yellow);
    painter.setBrush(brush);
    painter.drawRect(10, 15, 90, 60);

    painter.setBrush(Qt::VerPattern);
    painter.drawRect(130, 15, 90, 60);

    painter.setBrush(Qt::CrossPattern);
    painter.drawRect(250, 15, 90, 60);

    painter.setBrush(Qt::Dense7Pattern);
    painter.drawRect(10, 105, 90, 60);

    painter.setBrush(Qt::Dense6Pattern);
    painter.drawRect(130, 105, 90, 60);

    painter.setBrush(Qt::Dense5Pattern);
    painter.drawRect(250, 105, 90, 60);

    painter.setBrush(Qt::BDiagPattern);
    painter.drawRect(10, 195, 90, 60);

    painter.setBrush(Qt::FDiagPattern);
    painter.drawRect(130, 195, 90, 60);

    painter.setBrush(Qt::DiagCrossPattern);
    painter.drawRect(250, 195, 90, 60);
}
