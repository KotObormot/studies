#include <QCheckBox>
#include <QHBoxLayout>
#include "checkbox.h"

CheckBox::CheckBox(QWidget *parent) : QWidget(parent) {

    QHBoxLayout *hbox = new QHBoxLayout(this);

    QCheckBox *chB = new QCheckBox("Show title", this);
    chB->setCheckState(Qt::Checked);
    hbox->addWidget(chB, 0, Qt::AlignLeft | Qt::AlignTop);

    // В Qt 6 сигнал QCheckBox::stateChanged стал устаревшим (deprecated), так как он передавал целочисленное значение int (состояния Qt::CheckState).
    //connect(chB, &QCheckBox::stateChanged, this, &CheckBox::showTitle);

    // Вместо него для отслеживания изменения состояния чекбокса теперь нужно использовать сигнал checkStateChanged.
    connect(chB, &QCheckBox::checkStateChanged, this, &CheckBox::showTitle);

}

CheckBox::~CheckBox() {}

//Тогда нужно и слот переделать:
//void CheckBox::showTitle(int state) {
//    if(state == Qt::Checked) {
//        setWindowTitle("QCheckbox");
//    } else {
//        setWindowTitle(" ");
//    }
//}

/*Чтобы сделать код еще компактнее, условие if-else в обоих вариантах можно заменить на тернарный оператор:

void CheckBox::showTitle(Qt::CheckState state) {
    if (state == Qt::Checked) {
        setWindowTitle("QCheckbox");
    } else {
        setWindowTitle(" ");
    }
}*/

void CheckBox::showTitle(Qt::CheckState state) {
    setWindowTitle(state == Qt::Checked ? "QCheckbox" : " ");
}
