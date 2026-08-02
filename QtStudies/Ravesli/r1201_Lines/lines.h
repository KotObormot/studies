#pragma once

#ifndef LINES_H
#define LINES_H

#include <QWidget>

class Lines : public QWidget {
    // Q_OBJECT

  public:
    Lines(QWidget *parent = nullptr);
    ~Lines();

  protected:
    void paintEvent(QPaintEvent*);
    void drawLines(QPainter*);
};
#endif // LINES_H
