#pragma once

#ifndef ANOTHERMENU_H
#define ANOTHERMENU_H

#include <QMainWindow>
#include <QApplication>
//#include <QAction>

class AnotherMenu : public QMainWindow
{
    Q_OBJECT

public:
    AnotherMenu(QWidget *parent = nullptr);
    ~AnotherMenu();
};
#endif // ANOTHERMENU_H
