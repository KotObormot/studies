#pragma once

#ifndef PROGRESSBAREX_H
#define PROGRESSBAREX_H

#include <QWidget>
#include <QProgressBar>
#include <QPushButton>

class ProgressBarEx : public QWidget {
    Q_OBJECT

  public:
    ProgressBarEx(QWidget *parent = nullptr);
    ~ProgressBarEx();

  private:
    int progress;
    QTimer *timer;
    QProgressBar *pBar;
    QPushButton *startBttn;
    QPushButton *stopBttn;
    static const int DELAY = 200;
    static const int MAX_VALUE = 100;

    void updateBar();
    void startTimer();
    void stopTimer();
};
#endif // PROGRESSBAREX_H
