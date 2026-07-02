#pragma once

#ifndef KEYPRESS_H
#define KEYPRESS_H

#include <QWidget>
#include <QApplication>

class KeyPress : public QWidget {
    Q_OBJECT

  public:
    KeyPress(QWidget *parent = nullptr);
    ~KeyPress();

  protected:
    void keyPressEvent(QKeyEvent *e);
};
#endif // KEYPRESS_H
