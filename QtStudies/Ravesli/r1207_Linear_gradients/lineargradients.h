#pragma once

#ifndef LINEARGRADIENTS_H
#define LINEARGRADIENTS_H

#include <QWidget>

class LinearGradients : public QWidget {
    //Q_OBJECT

  public:
    LinearGradients(QWidget *parent = nullptr);
    ~LinearGradients();

  protected:
    void paintEvent(QPaintEvent*);

  private:
    void doPainting();
};
#endif // LINEARGRADIENTS_H
