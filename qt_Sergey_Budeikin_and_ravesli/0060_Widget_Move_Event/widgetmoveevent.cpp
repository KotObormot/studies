#include "widgetmoveevent.h"
#include <QMoveEvent>

WidgetMoveEvent::WidgetMoveEvent(QWidget *parent) : QWidget(parent) {}

void WidgetMoveEvent::moveEvent(QMoveEvent *e) {

    //Мы используем объект класса QMoveEvent для определения значений x и y:
    int x = e->pos().x();
    int y = e->pos().y();

    //Затем мы конвертируем целочисленные значения в строки:
    QString text = QString::number(x) + ", " + QString::number(y);

    //И с помощью метода setWindowTitle() устанавливаем текст в заголовок окна:
    setWindowTitle(text);
}

WidgetMoveEvent::~WidgetMoveEvent() {}
