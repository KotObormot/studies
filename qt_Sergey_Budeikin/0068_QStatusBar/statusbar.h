#pragma once

#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QMainWindow>
#include <QPushButton>
#include <QFrame>
#include <QStatusBar>
#include <QHBoxLayout>

class StatusBar : public QMainWindow {
    Q_OBJECT

  public:
    StatusBar(QWidget *parent = nullptr);
    ~StatusBar();

  private slots:
    void OnOkPressed();
    void OnAplayPressed();

  private:
    QPushButton *okBttn;
    QPushButton *applyBttn;
};
#endif // STATUSBAR_H
