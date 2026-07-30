#include <QHBoxLayout>
#include <QTableWidget>
#include "table.h"

Table::Table(QWidget *parent) : QWidget(parent) {

    QHBoxLayout *hbox = new QHBoxLayout(this);

    // Создаем виджет таблицы с 25-ю строками и 25-ю столбцами:
    QTableWidget *table = new QTableWidget(25, 25, this);

    hbox->addWidget(table);
}

Table::~Table() {}
