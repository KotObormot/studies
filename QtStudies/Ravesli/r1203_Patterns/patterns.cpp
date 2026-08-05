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
//////////////////////////////////////////////////////////////////////////////// 1
    // Создаем прямоугольник с определенным рисунком.
    // Qt::HorPattern — это константа, используемая для создания шаблона горизонтальных линий:
    //painter.setBrush(Qt::HorPattern);

    //QPen pen(QColor("#0000ff"), 3); // Настройка рамки (толщина 3 пикселя, синий цвет)
    QPen pen1(QColor("blue"), 3);
    painter.setPen(pen1);

    // 2. Настройка белого фона под узором
    painter.setBackgroundMode(Qt::OpaqueMode); // Включаем видимость фона под текстурой
    painter.setBackground(QBrush(Qt::white));  // Задаем белый цвет фона

    // Чтобы внутри прямоугольника одновременно отображался узор и белый цвет фона, вам нужно настроить оба свойства в одном объекте QBrush.
    // Var. 1:
    QBrush brush(QColor("#f44336"), Qt::HorPattern);    // Конструктор QBrush: Принимает сразу два параметра — цвет (QColor white) и стиль заполнения (Qt::BrushStyle).
    painter.setBrush(brush);    // Цвет самого узора (линий) в данном случае будет браться из текущего пера painter.pen().

    painter.drawRect(10, 15, 90, 60);
///////////////////////////////////////////////////////////////////////////////////// 2
    // Var. 2
    // Если вы хотите полностью контролировать цвет линий узора и цвет фона под узором, можно использовать альтернативный вариант с настройкой палитры brush:
    //QBrush brush(Qt::HorPattern);
    //brush.setColor(Qt::yellow);
    //painter.setBrush(brush);

    QPen pen2(QColor("green"), 5);
    painter.setPen(pen2);
    painter.setBackground(QBrush("yellow"));
    painter.setBrush(Qt::VerPattern);
    painter.drawRect(130, 15, 90, 60);

//////////////////////////////////////////////////////////////////////////////////////// 3
    QPen pen3(QColor("purple"), 5);
    painter.setPen(pen3);

    painter.setBrush(Qt::CrossPattern);
    painter.drawRect(250, 15, 90, 60);
//////////////////////////////////////////////////////////////////////////////////////// 4
    painter.setPen(pen1);
    painter.setBackground(QColor("white"));
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
