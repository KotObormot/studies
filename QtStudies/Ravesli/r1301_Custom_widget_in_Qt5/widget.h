#pragma once

#ifndef WIDGET_H
#define WIDGET_H

#include <QFrame>

class Burning;

class Widget : public QFrame {

  public:
    Widget(QWidget *parent = nullptr);
    ~Widget() = default;

  protected:
    void paintEvent(QPaintEvent *);
    void drawWidget(QPainter &qp);

  private:
    QWidget *m_parent; // Мы храним указатель на родительский виджет, т.к. через него мы будем обращаться к переменной cur_width:
    Burning *burn;

    static const int DISTANCE = 19;                     //это расстояние между значениями шкалы.
    static const int LINE_WIDTH = 5;                    // это длина вертикальных линий-насечек шкалы.
    static const int DIVISIONS = 10;                    //  это количество частей шкалы.
    constexpr static const float FULL_CAPACITY = 700;   // это ёмкость «диска».
    constexpr static const float MAX_CAPACITY = 750;    // максимальная ёмкость носителя.
};

#endif // WIDGET_H
