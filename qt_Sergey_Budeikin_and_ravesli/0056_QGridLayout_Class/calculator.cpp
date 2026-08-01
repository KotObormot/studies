#include "calculator.h"
#include <QPushButton>

Calculator::Calculator(QWidget *parent) : QWidget(parent) {
    // создаем компоновку по сетке и устанавливаем 2 пикселя пространства между дочерними виджетами:
    grid = new QGridLayout(this);
    grid->setSpacing(2);

    // символы, которые отображаются на кнопках:
    QList<QString> values({"7", "8", "9", "/"
                         , "4", "5", "6", "*"
                         , "1", "2", "3", "-"
                         , "0", ".", "=", "+"
    });

    // помещаем шестнадцать виджетов в компоновку. Все кнопки имеют фиксированный размер:
    int pos = 0;
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            QPushButton *btn = new QPushButton(values[pos], this);
            btn->setFixedSize(40, 40);
            grid->addWidget(btn, i, j);
            ++pos;
        }
    }

    setLayout(grid);
}

Calculator::~Calculator() {}

/*
В калькуляторе решил добавить обработчики нажатия кнопок. Ниже в коментариях нашел как получить доступ к каждому элементу списка кнопок:
QList<QPushButton*> plist=window.findChildren<QPushButton*>();

В результате получилась громоздкая конструкция из коннектов
connect(plist[0], &QPushButton::clicked, this, &Calculator::OnPress8);
connect(plist[1], &QPushButton::clicked, this, &Calculator::OnPress7);

и куча почти одинаковых слотов нажатия кнопок.
Чтобы избавиться от дублирования кода надо как-то подключить к разным сигналам один слот и передать в слот аргумент — номер нажатой клавиши, например просто элемент массива QList<QString> values = { «7», «8»,….
Дочитал уроки по Qt до конца но решения так и не нашел. Гугление и изучение заняло довольно много времени…

Решением оказалось простым — применение лямбда-функции. Описание тут: https://wiki.qt.io/New_Signal_Slot_Syntax
В цикле создания кнопок добавилась одна строчка:
connect(btn, &QPushButton::clicked, this, [=]() { this->onPress(pos); }); //подключаем обработчик с аргументом

И единственный метод в слоте private slots:
void Calculator::onPress(int val) {
QString sop = values[val];
if (sop == "+" || sop == "-" || sop == "/" || sop == "*" || sop == "=") {...} //обработка нажатия кнопок действий
else {...} //обработка нажатия кнопок цифр
}
*/
