#pragma once

#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>
#include <QList>

class Snake : public QWidget
{
    Q_OBJECT

  public:
    Snake(QWidget *parent = nullptr);
    ~Snake() = default;


};
#endif // SNAKE_H
