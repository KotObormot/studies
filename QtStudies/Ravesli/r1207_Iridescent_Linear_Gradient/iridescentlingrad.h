#pragma once

#ifndef IRIDESCENTLINGRAD_H
#define IRIDESCENTLINGRAD_H

#include <QWidget>
#include <QLinearGradient>
#include <QPainter>
#include <QTimer>

class IridescentLinGrad : public QWidget {

    Q_OBJECT

  public:
    IridescentLinGrad(QWidget *parent = nullptr);
    ~IridescentLinGrad() = default;

  protected:
    void paintEvent(QPaintEvent*) override;

  private:
    QLinearGradient m_gradVer;

    // Добавляем переменную шага анимации m_offset и объект таймера m_timer.
    QTimer m_timer;           // Таймер для анимации
    double m_offset = 0.0;    // Смещение цветов (от 0.0 до 1.0)
};
#endif // IRIDESCENTLINGRAD_H
