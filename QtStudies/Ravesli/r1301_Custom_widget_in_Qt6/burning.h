#pragma once

#ifndef BURNING_H
#define BURNING_H

//#include <QWidget>
#include "progressline.h"

class Burning : public QWidget {
    Q_OBJECT

  public:
    Burning(QWidget *parent = nullptr);
    ~Burning() = default;
};
#endif // BURNING_H
