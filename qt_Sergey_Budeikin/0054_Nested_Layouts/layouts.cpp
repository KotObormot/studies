#include "layouts.h"

Layouts::Layouts(QWidget *parent) : QWidget(parent) {
    vbox = new QVBoxLayout();       // without a parent
    hbox = new QHBoxLayout(this);

    lw = new QListWidget(this);
    lw->addItem("The Omen");
    lw->addItem("The Exorcist");
    lw->addItem("Notes on a Scandal");
    lw->addItem("Fargo");
    lw->addItem("Capote");

    add = new QPushButton("Add", this);
    rename = new QPushButton("Rename", this);
    remove = new QPushButton("Remove", this);
    removeall = new QPushButton("Remove All", this);

    //Создается вертикальная компоновка с четырьмя кнопками. Мы вставили немного свободного места между нашими кнопками.
    //Обратите внимание, что мы добавляем коэффициент растяжения к верхней и нижней части вертикальной компоновки.
    //Таким образом, кнопки расположены вертикально по центру:
    vbox->setSpacing(3);
    vbox->addStretch(1);
    vbox->addWidget(add);
    vbox->addWidget(rename);
    vbox->addWidget(remove);
    vbox->addWidget(removeall);
    vbox->addStretch(1);

    //Виджет списка и вертикальный блок кнопок помещаются в блок горизонтальной компоновки.
    //Метод addLayout() используется для вложения одной компоновки в другую:
    hbox->addWidget(lw);
    hbox->addSpacing(15);
    hbox->addLayout(vbox);

    //Устанавливаем базовую компоновку для родительского окна:
    setLayout(hbox);
}

Layouts::~Layouts() {}
