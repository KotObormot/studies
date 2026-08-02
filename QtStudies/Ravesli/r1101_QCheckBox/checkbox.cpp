#include <QCheckBox>
#include <QHBoxLayout>
#include "checkbox.h"

CheckBox::CheckBox(QWidget *parent) : QWidget(parent) {

    QHBoxLayout *hbox = new QHBoxLayout(this);

    QCheckBox *cb = new QCheckBox("Show Title", this);
    cb->setCheckState(Qt::Checked);
    hbox->addWidget(cb, 0, Qt::AlignLeft | Qt::AlignTop);

    // connect(cb, &QCheckBox::stateChanged, this, &CheckBox::showTitle);
    connect(cb, &QCheckBox::checkStateChanged, this, &CheckBox::showTitle);
}

CheckBox::~CheckBox() {}

// DEPRECATED
/*void CheckBox::showTitle(int state) {

    if (state == Qt::Checked) {
        setWindowTitle("QCheckBox");
    } else {
        setWindowTitle(" ");
    }
}*/

    // Вариант 1: Через toggled (Рекомендуемый)
/*void CheckBox::showTitle(bool checked) {

    if(checked) {
        setWindowTitle("QCheckbox");
    } else {
        setWindowTitle(" ");
    }
}*/

// Вариант 2: Через checkStateChanged (Если важно перечисление)
/*void CheckBox::showTitle(Qt::CheckState state) {

    if(state == Qt::Checked) {
        setWindowTitle("QCheckbox");
    } else {
        setWindowTitle(" ");
    }
}*/

// Чтобы сделать код еще компактнее, условие if-else в обоих вариантах можно заменить на тернарный оператор:
void CheckBox::showTitle(Qt::CheckState state) {
    setWindowTitle(state == Qt::Checked ? "CheckBox" : " ");
}
