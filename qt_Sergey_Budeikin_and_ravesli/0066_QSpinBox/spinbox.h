#pragma once

#ifndef SPINBOX_H
#define SPINBOX_H

#include <QWidget>
#include <QSpinBox>

class SpinBox : public QWidget {
    Q_OBJECT

  public:
    SpinBox(QWidget *parent = nullptr);
    ~SpinBox();

  private:
    QSpinBox *spinbox;
};
#endif // SPINBOX_H
