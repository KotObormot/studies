#pragma once

#ifndef BURNING_H
#define BURNING_H

#include <QWidget>
#include <QSlider>
#include <QFrame>
#include "widget.h"

class Burning : public QFrame {
    Q_OBJECT

  public:
    Burning(QWidget *parent = nullptr);
    ~Burning() = default;
    int getCurrentWidth();      // Метод getCurrentWidth() используется для определения значений ползунка:

  public slots:
    void valueChanged(int);

  private:
    // В клиентской области окна у нас будет два виджета: встроенный виджет слайдера и пользовательский виджет.
    QSlider *slider;
    QWidget *widget;
    // Переменная cur_width будет содержать текущее значение ползунка слайдера. Это значение используется при рисовании пользовательского виджета:
    int cur_width;

    void initUI();
};
#endif // BURNING_H
