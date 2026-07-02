#include "keypress.h"
#include <QKeyEvent>

KeyPress::KeyPress(QWidget *parent) : QWidget(parent) {}

void KeyPress::keyPressEvent(QKeyEvent *event) {
    // Одним из способов работы с событиями в Qt5 является переопределение обработчика событий.
    //QKeyEvent — это класс, который содержит информацию о произошедшем событии.
    //В нашем случае мы используем объект данного класса для определения того, что была нажата именно клавиша Esc:
    if(event->key() == Qt::Key_Escape) {
        qApp->quit();
    }
}

KeyPress::~KeyPress() {}
