#include "verticalbox.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

VerticalBox::VerticalBox(QWidget *parent) : QWidget(parent) {

    //Создаем объект класса QVBoxLayout и устанавливаем интервал между дочерними виджетами в 1 пиксель:
    //QVBoxLayout *vbox = new QVBoxLayout(this);
    QHBoxLayout *vbox = new QHBoxLayout(this);
    vbox->setSpacing(100);

    //Далее мы создаем кнопку и устанавливаем для нее политику размера QSizePolicy::Expanding.
    //Дочерние виджеты управляются менеджером компоновки.
    //По умолчанию кнопка растягивается по горизонтали и имеет фиксированный размер по вертикали.
    //Если мы хотим изменить его, то нужно и для вертикали установить новую политику размера (QSizePolicy::Expanding).
    //Как видите, в нашем случае кнопка будет расширяться в обоих направлениях
    QPushButton *settings = new QPushButton("Settings", this);
    settings->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QPushButton *accounts = new QPushButton("Accounts", this);
    accounts->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QPushButton *loans = new QPushButton("Loans", this);
    loans->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QPushButton *cash = new QPushButton("Cash", this);
    cash->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QPushButton *debts = new QPushButton("Debts", this);
    debts->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //Добавляем дочерние виджеты в менеджер компоновки при помощи метода addWidget():
    vbox->addWidget(settings);
    vbox->addWidget(accounts);
    vbox->addWidget(loans);
    vbox->addWidget(cash);
    vbox->addWidget(debts);

    //Сообщаем нашей программе, что необходимо использовать QVBoxLayout в качестве менеджера компоновки
    setLayout(vbox);
}

VerticalBox::~VerticalBox() {}
