#include <QPixmap>
#include <QLabel>
#include <QHBoxLayout>
#include "pixmap.h"

Pixmap::Pixmap(QWidget *parent) : QWidget(parent) {

    QHBoxLayout *hbox = new QHBoxLayout(this);

    //Мы создаем pixmap — пространство, в которое поместим наше растровое изображение. Затем созданный pixmap мы помещаем в виджет метки:
    QPixmap pixmap("://images/bagulnik_ostrokonechniy_02.jpg");

    QLabel *label = new QLabel(this);
    label->setPixmap(pixmap);

    hbox->addWidget(label, 0, Qt::AlignTop);
}

Pixmap::~Pixmap() {}
