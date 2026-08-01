#pragma once

#ifndef ABSOLUTE_H
#define ABSOLUTE_H

#include <QWidget>
#include <QApplication>

class Absolute : public QWidget {
    Q_OBJECT

  public:
    Absolute(QWidget *parent = nullptr);
    ~Absolute();
};
#endif // ABSOLUTE_H
