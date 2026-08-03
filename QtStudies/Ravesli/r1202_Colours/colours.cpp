#include <QPainter>
#include "colours.h"

Colours::Colours(QWidget *parent) : QWidget(parent) {}

Colours::~Colours() {}

void Colours::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);

    doPainting();
}

void Colours::doPainting() {

    QPainter painter(this);
    painter.setPen(QColor(0xd4d4d4));

    // Класс кисти QBrush определяет шаблон заливки фигур, нарисованных с помощью объекта класса QPainter.
    // Метод drawRect() рисует прямоугольник:
    //      первые два параметра метода — это координаты (x;y) верхнего левого угла прямоугольника;
    //      другие два параметра — это значения ширины прямоугольника и его высоты.
    // Для указания цвета мы будем использовать шестнадцатеричное представление:
    painter.setBrush(QBrush("#c56c00"));
    painter.drawRect(10, 15, 90, 60);

    painter.setBrush(QBrush("#1ac500"));
    painter.drawRect(130, 15, 90, 60);

    //painter.setBrush(QBrush("#539e47"));
    painter.setBrush(QBrush("#ffffff"));    // white
    painter.drawRect(250, 15, 90, 60);

    painter.setBrush(QBrush("#004fc5"));
    painter.drawRect(10, 105, 90, 60);

    painter.setBrush(QBrush("#c50024"));
    //painter.setBrush(QBrush("#000000"));
    painter.drawRect(130, 105, 90, 60);

    painter.setBrush(QBrush("#9e4757"));
    painter.drawRect(250, 105,90, 60);

    painter.setBrush(QBrush("#5f3b00"));
    painter.drawRect(10, 195, 90, 60);

    //painter.setBrush(QBrush("#4c4c4c"));
    painter.setBrush(QBrush("#000000"));    // black
    painter.drawRect(130, 195, 90, 60);

    painter.setBrush(QBrush("#785f36"));
    painter.drawRect(250, 195, 90, 60);
}
