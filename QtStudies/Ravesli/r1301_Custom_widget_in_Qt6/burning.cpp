#include <QBoxLayout>
#include <QSlider>
#include "burning.h"

Burning::Burning(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *vbox = new QVBoxLayout(this);
    QHBoxLayout *hbox = new QHBoxLayout();
    QSlider *slider = new QSlider(Qt::Horizontal);
    ProgressLine *pl = new ProgressLine();
    vbox->setSpacing(20);
    hbox->addWidget(slider);
    hbox->addStretch(1);
    vbox->addLayout(hbox);
    vbox->addWidget(pl);

    setLayout(vbox);

    connect(slider, &QSlider::valueChanged, pl, &ProgressLine::setValue); // соединяем изменение значения слайдера с сеттером класса ProgressLine

    this->resize(300, 100);
    this->setMinimumSize(300, 100);
}

//Burning::~Burning() {}
