#pragma once

#ifndef RADIALGRADIENT_H
#define RADIALGRADIENT_H

#include <QWidget>
#include <QRadialGradient>
#include <QPainter>
#include <QTimer>
#include <QWheelEvent>      // Добавили для обработки колесика

class RadialGradient : public QWidget {
    Q_OBJECT

  public:
    RadialGradient(QWidget *parent = nullptr);
    ~RadialGradient() = default;

  protected:
    void paintEvent(QPaintEvent *) override;
    void wheelEvent(QWheelEvent *) override;

  private:
    QRadialGradient m_gradRad;
    QTimer m_timer;
    double m_offset = 0.0;
    double m_speed = 0.005;     // Базовая скорость анимации
};
#endif // RADIALGRADIENT_H
