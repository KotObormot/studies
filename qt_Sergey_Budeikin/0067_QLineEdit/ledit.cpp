#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include "ledit.h"

Ledit::Ledit(QWidget *parent) : QWidget(parent) {

    QLabel *name = new QLabel("Name:", this);
    name->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLabel *age = new QLabel("Age:", this);
    age->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLabel *occupation = new QLabel("Occupation:", this);
    occupation->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QLineEdit *leName = new QLineEdit(this);
    QLineEdit *leAge = new QLineEdit(this);
    QLineEdit *leOccuptn = new QLineEdit(this);

    QGridLayout *grid = new QGridLayout();

    grid->addWidget(name, 0, 0);
    grid->addWidget(leName, 0, 1);
    grid->addWidget(age, 1, 0);
    grid->addWidget(leAge, 1, 1);
    grid->addWidget(occupation, 2, 0);
    grid->addWidget(leOccuptn, 2, 1);

    setLayout(grid);
}

Ledit::~Ledit() {}
