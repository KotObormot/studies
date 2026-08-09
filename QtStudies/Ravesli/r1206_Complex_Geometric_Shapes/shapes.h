#pragma once

#ifndef SHAPES_H
#define SHAPES_H

#include <QWidget>

class Shapes : public QWidget {
    // Q_OBJECT

  public:
    Shapes(QWidget *parent = nullptr);
    ~Shapes();

  protected:
    void paintEvent(QPaintEvent*);

  private:
    void doPainting();
};
#endif // SHAPES_H
