#pragma once

#ifndef TABLE_H
#define TABLE_H

#include <QWidget>

class Table : public QWidget {
    Q_OBJECT

  public:
    Table(QWidget *parent = nullptr);
    ~Table();
};
#endif // TABLE_H
