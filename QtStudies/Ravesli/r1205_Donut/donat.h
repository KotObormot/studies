#pragma once

#ifndef DONAT_H
#define DONAT_H

#include <QWidget>

class Donat : public QWidget {
    Q_OBJECT

  public:
    Donat(QWidget *parent = nullptr);
    ~Donat();

  protected:
    void paintEvent(QPaintEvent*);

  private:
    void doPainting();
};
#endif // DONAT_H
