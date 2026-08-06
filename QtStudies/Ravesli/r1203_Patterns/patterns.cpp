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
    painter.setPen(Qt::NoPen);
//////////////////////////////////////////////////////////////////////////////// 1
    // Создаем прямоугольник с определенным рисунком.
    // Qt::HorPattern — это константа, используемая для создания шаблона горизонтальных линий:
    //painter.setBrush(Qt::HorPattern);

    //QPen pen(QColor("#0000ff"), 3); // Настройка рамки (толщина 3 пикселя, синий цвет)

/////////////////////////////////////// 1
    //painter.setPen(pen1);

    // 2. Настройка  фона под узором (orange)
    painter.setBackgroundMode(Qt::OpaqueMode); // Включаем видимость фона под текстурой
    painter.setBackground(QBrush("orange"));  // Задаем цвет фона orange

    // Чтобы внутри прямоугольника одновременно отображался узор и белый цвет фона, вам нужно настроить оба свойства в одном объекте QBrush.
    // Var. 1:
    QBrush brushHor(QColor("white"), Qt::HorPattern);    // Конструктор QBrush: Принимает сразу два параметра — цвет (QColor white) и стиль заполнения (Qt::BrushStyle).
    painter.setBrush(brushHor);    // Цвет самого узора (линий) в данном случае будет браться из текущего пера painter.pen(). WHY????????!!!!!!!
    painter.drawRect(10, 15, 90, 60);


//////////////////////////////////////// 2
    QPen penGreen(QColor("green"), 5);
    painter.setPen(penGreen);
    // Var. 2
    // Если вы хотите полностью контролировать цвет линий узора и цвет фона под узором, можно использовать альтернативный вариант с настройкой палитры brush:
    QBrush brushVer(Qt::VerPattern);
    brushVer.setColor(Qt::blue);
    painter.setBrush(brushVer);

    painter.setBackground(QBrush("red"));
    painter.drawRect(130, 15, 90, 60);

//////////////////////////////////////// 3
    QPen penPurple(QColor("purple"), 5);
    painter.setPen(penPurple);
    painter.setBackground(QBrush("black"));
    QBrush brushCross(Qt::CrossPattern);
    brushCross.setColor(Qt::white);
    painter.setBrush(brushCross);
    painter.drawRect(250, 15, 90, 60);

/////////////////////////////////////// 4
    QPen penBlue(QColor("blue"), 3);        // Настройка рамки (толщина 3 пикселя, синий цвет)
    painter.setPen(penBlue);
    painter.setBackground(QColor("black"));
    QBrush brushD7(QColor("white"), Qt::Dense7Pattern);
    painter.setBrush(brushD7);
    painter.drawRect(10, 105, 90, 60);

/////////////////////////////////////// 5
    painter.setPen(penGreen);
    painter.setBackground(QBrush("blue"));
    QBrush brushD6(QColor("red"), Qt::Dense6Pattern);
    painter.setBrush(brushD6);
    painter.drawRect(130, 105, 90, 60);

/////////////////////////////////////// 6
    painter.setPen(penPurple);
    painter.setBackground(QColor("red"));
    QBrush brashD5(Qt::Dense5Pattern);
    brashD5.setColor(Qt::green);
    painter.setBrush(brashD5);
    painter.drawRect(250, 105, 90, 60);

/////////////////////////////////////// 7
    painter.setPen(penGreen);
    painter.setBackground(QBrush("blue"));
    QBrush brushBDiag(QColor("white"), Qt::BDiagPattern);
    painter.setBrush(brushBDiag);
    painter.drawRect(10, 195, 90, 60);

/////////////////////////////////////// 8
    painter.setPen(penPurple);
    painter.setBackground(QBrush("white"));
    QBrush brushFDiag(QColor("blue"), Qt::FDiagPattern);
    painter.setBrush(brushFDiag);
    painter.drawRect(130, 195, 90, 60);

/////////////////////////////////////// 9
    painter.setPen(Qt::NoPen);
    painter.setBackground(QBrush("purple"));
    QBrush brushCrossDiag(Qt::DiagCrossPattern);
    brushCrossDiag.setColor(Qt::white);
    painter.setBrush(brushCrossDiag);
    painter.drawRect(250, 195, 90, 60);
}
