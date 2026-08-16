#pragma once

#ifndef LINGRAD_H
#define LINGRAD_H

#include <QWidget>
#include <QLinearGradient>
#include <QPainter>

class LinGrad : public QWidget {
    Q_OBJECT

  public:
    LinGrad(QWidget *parent = nullptr);
    ~LinGrad() = default;

  protected:
    void paintEvent(QPaintEvent *);

  private:
    QLinearGradient m_gradVer;
};
#endif // LINGRAD_H
