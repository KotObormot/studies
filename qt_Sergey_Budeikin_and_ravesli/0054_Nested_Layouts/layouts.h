#pragma once

#ifndef LAYOUTS_H
#define LAYOUTS_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QListWidget>

class Layouts : public QWidget {
    Q_OBJECT

  public:
    Layouts(QWidget *parent = nullptr);
    ~Layouts();

  private:
    //QVBoxLayout будет столбцом для кнопок:
    QVBoxLayout *vbox;

    // QHBoxLayout будет базовой компоновкой для виджетов:
    QHBoxLayout *hbox;

    // Создаем QListWidget
    QListWidget *lw;

    // А теперь создаем наши кнопки:
    QPushButton *add;
    QPushButton *rename;
    QPushButton *remove;
    QPushButton *removeall;
};
#endif // LAYOUTS_H
