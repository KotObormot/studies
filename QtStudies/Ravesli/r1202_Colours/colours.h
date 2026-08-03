#pragma once

#ifndef COLOURS_H
#define COLOURS_H

#include <QWidget>

class Colours : public QWidget {
    // Q_OBJECT

  public:
    Colours(QWidget *parent = nullptr);
    ~Colours();

  protected:
    void paintEvent(QPaintEvent*);

  private:
    void doPainting();
};
#endif // COLOURS_H
