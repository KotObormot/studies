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
    // DEPRECATED
    // void showTitle(int);

    // Вариант 1: Через toggled (Рекомендуемый)
/*      void showTitle(bool);*/

    //  Вариант 2: Через checkStateChanged (Если важно перечисление)
    void showTitle(Qt::CheckState);
};
#endif // CHECKBOX_H
