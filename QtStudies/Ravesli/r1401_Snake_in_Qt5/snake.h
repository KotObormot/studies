#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>

class Snake : public QWidget
{
    Q_OBJECT

public:
    Snake(QWidget *parent = nullptr);
    ~Snake();
};
#endif // SNAKE_H
