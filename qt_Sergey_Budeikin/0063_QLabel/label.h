#pragma once

#ifndef LABEL_H
#define LABEL_H

#include <QWidget>
#include <QLabel>

class Label : public QWidget {
    Q_OBJECT

  public:
    Label(QWidget *parent = nullptr);
    ~Label();

  private:
    QLabel *label;
};
#endif // LABEL_H
