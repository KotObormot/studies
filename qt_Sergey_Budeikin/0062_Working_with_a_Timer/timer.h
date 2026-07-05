#pragma once

#ifndef TIMER_H
#define TIMER_H

#include <QWidget>
#include <QLabel>

class Timer : public QWidget {
    Q_OBJECT

  public:
    Timer(QWidget *parent = nullptr);
    ~Timer();

  protected:
    void timerEvent(QTimerEvent* event);

  private:
    QLabel *label;
};
#endif // TIMER_H
