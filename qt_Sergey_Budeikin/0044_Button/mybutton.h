#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>

class MyButton : public QWidget
{
    Q_OBJECT        // Макрос необходим для работы сигналов и слотов

public:
    MyButton(QWidget *parent = nullptr);
    ~MyButton();
};
#endif // MYBUTTON_H
