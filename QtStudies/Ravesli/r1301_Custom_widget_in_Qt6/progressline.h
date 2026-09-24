#pragma once

#ifndef PROGRESSLINE_H
#define PROGRESSLINE_H

#include <QWidget>
#include <QFrame>
#include <QPainter>

class ProgressLine : public QFrame {
    Q_OBJECT
  public:
    explicit ProgressLine(QFrame *parent = nullptr
                            , int min = 0
                            , int max = 100
                            , int points = 11
                            , int orange_zone = 70
                            , int red_zone = 90);

  //signals:

  private:
    void paintEvent(QPaintEvent *);
    void doPainting();

  public:
    void setValue(int value = 0);

  private:
    static const int M_LINE_HEIGHT = 5;                      // высота линий
    static const int M_FONT_SIZE = 10;                      // размер шрифта
    static const int M_PIXELS_BETWEEN_LINE_AND_TEXT = 2;     // расстояние между линиями и числами

  private:
    int m_value;            // главное значение виджета
    int m_min;              // минимум
    int m_max;              // максимум
    int m_count;            // количество линий (точек с числами, которые рисуем на виджете)
    int m_orange_zone;      // значение, где начинается оранжевая зона
    int m_red_zone;         // значение, где начинается красная зона
};

#endif // PROGRESSLINE_H
