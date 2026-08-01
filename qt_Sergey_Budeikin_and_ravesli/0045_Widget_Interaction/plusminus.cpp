#include "plusminus.h"

PlusMinus::PlusMinus(QWidget *parent) : QWidget(parent) {
    QPushButton *plusButton = new QPushButton("+", this);   // кнопка ПЛЮС
    QPushButton *minusButton = new QPushButton("-", this);  // кнопка минус
    lbl = new QLabel("0", this);                                // окошко с числом

    // Компоновка кнопок и лейбла в нашем виджете
    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(plusButton, 0, 0);
    grid->addWidget(minusButton, 0, 1);
    grid->addWidget(lbl, 1, 1);

    setLayout(grid);

    // подключение сигналов и слотов к кнопкам, здесь происходит соединение сигналов clicked с соответствующими слотами:
    connect(plusButton, &QPushButton::clicked, this, &PlusMinus::OnPlus);
    connect(minusButton, &QPushButton::clicked, this, &PlusMinus::OnMinus);
}

PlusMinus::~PlusMinus() {}

void PlusMinus::OnPlus() {
    /*В методе OnPlus() мы определяем текущее значение в lbl.
     *  Виджет lbl отображает строковое значение, поэтому сначала его нужно преобразовать в целое число.
     *  Затем мы это число увеличиваем, конвертируем получившееся число снова в строковое значение
     *   и устанавливаем новый текст для label*/
    int val = lbl->text().toInt();
    ++val;
    lbl->setText(QString::number(val));
}

void PlusMinus::OnMinus() {
    /*Метод OnMinus() отличается от метода OnPlus() только тем,
     * что в OnMinus() значение не инкрементируется, а декрементируется (уменьшается на единицу).*/
    int val = lbl->text().toInt();
    --val;
    lbl->setText(QString::number(val));
}
