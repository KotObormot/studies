#pragma once

#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QListWidget>

class ListWidget : public QWidget {
    Q_OBJECT

  public:
    ListWidget(QWidget *parent = nullptr);
    ~ListWidget();

  private slots:
    void AddItem();
    void renameItem();
    void removeItem();
    void clearItems();

  private:
    QListWidget *lw;
    QPushButton *add;
    QPushButton *rename;
    QPushButton *remove;
    QPushButton *removeAll;
};
#endif // LISTWIDGET_H
