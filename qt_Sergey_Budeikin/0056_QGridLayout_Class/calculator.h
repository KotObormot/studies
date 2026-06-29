#pragma once

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QGridLayout>

class Calculator : public QWidget {
    Q_OBJECT

  public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

  private:
    QGridLayout *grid;  //  создаем компоновку по сетке
};
#endif // CALCULATOR_H
