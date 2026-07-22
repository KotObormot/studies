#pragma once

#ifndef LEDIT_H
#define LEDIT_H

#include <QWidget>

class Ledit : public QWidget {
    Q_OBJECT

  public:
    Ledit(QWidget *parent = nullptr);
    ~Ledit();
};
#endif // LEDIT_H
