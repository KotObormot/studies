#pragma once

#ifndef COMBODOXEX_H
#define COMBODOXEX_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>

class ComboDoxEx : public QWidget {
    Q_OBJECT

  public:
    ComboDoxEx(QWidget *parent = nullptr);
    ~ComboDoxEx();

  private:
    QComboBox *combo;
    QLabel *label;

};
#endif // COMBODOXEX_H
