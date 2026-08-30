#pragma once

#ifndef RADIALGRADIENT_H
#define RADIALGRADIENT_H

#include <QWidget>
#include <QRadialGradient>
#include <QPainter>

class RadialGradient : public QWidget {
//    Q_OBJECT

  public:
    RadialGradient(QWidget *parent = nullptr);
    ~RadialGradient() = default;

  protected:
    void paintEvent(QPaintEvent *) override;

  private:
    QRadialGradient m_gradRad;

};
#endif // RADIALGRADIENT_H
