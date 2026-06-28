#pragma once

#ifndef BUTTONS_H
#define BUTTONS_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class Buttons : public QWidget {
    Q_OBJECT

  public:
    Buttons(QWidget *parent = nullptr);
    ~Buttons();

  private:
    // Нам потребуются два менеджера компоновки: один вертикальный и один горизонтальный.
    QVBoxLayout *vbox;
    QHBoxLayout *hbox;

    // Создаем две кнопки:
    QPushButton *okBtn;
    QPushButton *applyBtn;
};
#endif // BUTTONS_H
