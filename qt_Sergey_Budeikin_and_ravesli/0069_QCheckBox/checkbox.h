#pragma once

#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <QWidget>

class CheckBox : public QWidget {
    Q_OBJECT

  public:
    CheckBox(QWidget *parent = nullptr);
    ~CheckBox();

  private slots:
    // void showTitle(int);  deprecated!!
    void showTitle(Qt::CheckState);
};
#endif // CHECKBOX_H
