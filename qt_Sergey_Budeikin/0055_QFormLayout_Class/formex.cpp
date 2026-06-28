#include "formex.h"

FormEx::FormEx(QWidget *parent) : QWidget(parent) {
    // Определяем редактируемые поля для правого столбца
    nameEdit = new QLineEdit(this);
    addrEdit = new QLineEdit(this);
    ageEdit = new QLineEdit(this);

    formLayout = new QFormLayout;

    // С помощью метода setLabelAlignment() устанавливаем выравнивание виджетов-меток:
    formLayout->setLabelAlignment(Qt::AlignRight | Qt::AlignCenter);

    // Метод addRow() добавляет новую строку в нижнюю часть компоновки формы с заданной меткой и виджетом ввода:
    formLayout->addRow("Name: ", nameEdit);
    formLayout->addRow("E-mail: ", addrEdit);
    formLayout->addRow("Age: ", ageEdit);

    setLayout(formLayout);
}

FormEx::~FormEx() {}
