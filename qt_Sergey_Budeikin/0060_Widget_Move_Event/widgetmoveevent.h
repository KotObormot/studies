#pragma once

#ifndef WIDGETMOVEEVENT_H
#define WIDGETMOVEEVENT_H

#include <QWidget>
//#include <QMainWindow>

class WidgetMoveEvent : public QWidget {
    Q_OBJECT

  public:
    WidgetMoveEvent(QWidget *parent = nullptr);
    ~WidgetMoveEvent();

  protected:
    void moveEvent(QMoveEvent *e);
};
#endif // WIDGETMOVEEVENT_H
