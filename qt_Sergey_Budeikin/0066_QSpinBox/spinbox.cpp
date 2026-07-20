#include <QHBoxLayout>
#include <QLabel>
#include "spinbox.h"

SpinBox::SpinBox(QWidget *parent) : QWidget(parent) {

    QHBoxLayout *hbox = new QHBoxLayout(this);
    hbox->setSpacing(15);

    spinbox = new QSpinBox(this);

    QLabel *label = new QLabel("0", this);

    hbox->addWidget(spinbox);
    hbox->addWidget(label);

    // Нам нужно выполнить конвертацию с помощью оператора static_cast дважды, потому что и сигнал, и слот перегружены:
    //connect(spinbox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged)
    //        , label, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));

    // в Qt 6 у QSpinBox::valueChanged удалена перегрузка со строкой (QString), остался только вариант с int.
    //Сигнал больше не перегружен, поэтому static_cast для него не нужен.
    // Однако у QLabel::setNum перегрузка осталась (есть варианты для int и double). Чтобы связать их напрямую, в Qt 6 используется макрос qOverload.

    // Вариант 1: Через qOverload (Прямое подключение)
    // Мы убираем static_cast у сигнала и используем красивый qOverload для слота метки:
    //connect(spinbox, &QSpinBox::valueChanged
    //        , label, qOverload<int>(&QLabel::setNum));


    // Вариант 2: Через лямбда-выражение (Самый современный подход):
    connect(spinbox, &QSpinBox::valueChanged
            , label, [label](int value) {label->setNum(value);}
    );
}

SpinBox::~SpinBox() {}
