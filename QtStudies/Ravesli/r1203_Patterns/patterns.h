#pragma once

#ifndef PATTERNS_H
#define PATTERNS_H

#include <QWidget>

class Patterns : public QWidget {
    // Q_OBJECT

  public:
    Patterns(QWidget *parent = nullptr);
    ~Patterns();

  protected:
    void paintEvent(QPaintEvent*);

  private:
    void doPainting();
};
#endif // PATTERNS_H
