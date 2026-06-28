#pragma once

#ifndef FORMEX_H
#define FORMEX_H

#include <QWidget>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>

class FormEx : public QWidget {
    Q_OBJECT

  public:
    FormEx(QWidget *parent = nullptr);
    ~FormEx();

  private:
    // Объявляем редактируемые поля для правого столбца
    QLineEdit *nameEdit;
    QLineEdit *addrEdit;
    QLineEdit *ageEdit;

    // Создаем экземпляр класса QFormLayout
    QFormLayout *formLayout;
};
#endif // FORMEX_H
