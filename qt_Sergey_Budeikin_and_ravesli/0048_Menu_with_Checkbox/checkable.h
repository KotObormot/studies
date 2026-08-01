#pragma once

#ifndef CHECKABLE_H
#define CHECKABLE_H

#include <QMainWindow>
#include <QApplication>

class Checkable : public QMainWindow {
    Q_OBJECT

  public:
    Checkable(QWidget *parent = nullptr);
    ~Checkable();

  private slots:
    void toggleStatusbar();

  private:
    QAction *viewSt;
    QAction *quit;
};
#endif // CHECKABLE_H
