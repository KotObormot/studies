#include "absolute.h"
//#include <QDesktopWidget>
//<QDesktopWidget> был полностью удален из библиотеки.
//В Qt 5 он считался устаревшим (deprecated), а при переходе на Qt 6
//разработчики окончательно убрали его из состава модуля QtWidgets.
//Для работы с экранами, их размерами и геометрией теперь нужно использовать класс QScreen совместно с QGuiApplication.
#include <QGuiApplication>
#include <QScreen>
#include <QTextEdit>

Absolute::Absolute(QWidget *parent) : QWidget(parent) {
    QTextEdit *ledit = new QTextEdit(this);
    ledit->setGeometry(15, 5, 200, 150);
}

Absolute::~Absolute() {}
