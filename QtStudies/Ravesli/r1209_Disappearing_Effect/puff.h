#pragma once

#ifndef PUFF_H
#define PUFF_H

#include <QWidget>

class Puff : public QWidget {
//    Q_OBJECT

  public:
    Puff(QWidget *parent = nullptr);
    ~Puff() = default;

  protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);

  private:
    int x;
    qreal opacity;
    int timerId;
    void doPainting();
};
#endif // PUFF_H
