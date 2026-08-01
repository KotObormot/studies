#pragma once

#ifndef PLUSMINUS_H
#define PLUSMINUS_H

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

class PlusMinus : public QWidget {
    Q_OBJECT         // этот макрос должен включаться в классы, которые объявляют свои собственные сигналы и слоты

  public:
    PlusMinus(QWidget *parent = nullptr);
    ~PlusMinus();

  private slots:
    // У нас есть два слота == это методы, которые вызываются через connect
    void OnPlus();
    void OnMinus();

  private:
    // ... и виджет lbl
    QLabel *lbl;
};
#endif // PLUSMINUS_H
