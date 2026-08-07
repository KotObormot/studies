#pragma once

#ifndef TRANSPARENTRECTANGLES_H
#define TRANSPARENTRECTANGLES_H

#include <QWidget>

class TransparentRectangles : public QWidget {
    Q_OBJECT

  public:
    TransparentRectangles(QWidget *parent = nullptr);
    ~TransparentRectangles();

  protected:
    void paintEvent(QPaintEvent*);
    void doPainting();
};
#endif // TRANSPARENTRECTANGLES_H
