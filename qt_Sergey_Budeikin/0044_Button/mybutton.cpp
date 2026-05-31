#include "mybutton.h"
//#include <QApplication>

MyButton::MyButton(QWidget *parent) : QWidget(parent) {
    QPushButton *quitBtn = new QPushButton("QUIT", this);   // создаем новую кнопку
    quitBtn->setGeometry(50, 40, 75, 30);   // изменяем размеры кнопки в пикселях и помещаем на форму окна

    connect(quitBtn, &QPushButton::clicked, qApp, QApplication::quit);      // это и есть сигнал и слот
}

MyButton::~MyButton() {}
