#include "slider.h"
#include <QHBoxLayout>

Slider::Slider(QWidget *parent) : QWidget(parent) {

    QHBoxLayout *hbox = new QHBoxLayout(this);

    //Создаем горизонтальный QSlider // Let's create a horizontal QSlider:
    slider = new QSlider(Qt::Horizontal, this);
    hbox->addWidget(slider);

    label = new QLabel("0", this);
    hbox->addWidget(label);

    // Далее подключаем сигнал valueChanged() к встроенному в метку слоту setNum().
    //Поскольку метод setNum() перегружен, то мы используем оператор static_cast для выбора корректного метода:
    // Next, we connect the valueChanged() signal to the label's built-in setNum() slot.
    //    Since the setNum() method is overloaded, we use the static_cast operator to select the correct method:
    connect(slider, &QSlider::valueChanged,
            label, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));
}

Slider::~Slider() {}
