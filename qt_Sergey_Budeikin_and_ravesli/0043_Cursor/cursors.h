#ifndef CURSORS_H
#define CURSORS_H

#include <QWidget>
#include <QFrame>
#include <QGridLayout>

class Cursors : public QWidget
{
    Q_OBJECT

public:
    Cursors(QWidget *parent = nullptr);
    ~Cursors();
};
#endif // CURSORS_H
