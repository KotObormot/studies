#pragma once

#ifndef ADAPTIVELINEARGRADIENT_H
#define ADAPTIVELINEARGRADIENT_H

#include <QWidget>
#include <QLinearGradient>
#include <QPainter>

class AdaptiveLinearGradient : public QWidget {
    Q_OBJECT

  public:
    AdaptiveLinearGradient(QWidget *parent = nullptr);
    ~AdaptiveLinearGradient() = default;

  protected:
    void paintEvent(QPaintEvent*) override;

  private:
    // Градиент живет столько же, сколько и сам виджет
    QLinearGradient m_gradVer;
};
#endif // ADAPTIVELINEARGRADIENT_H
