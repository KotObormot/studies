#pragma once

#ifndef SIMPLEMENU_H
#define SIMPLEMENU_H

#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

class SimpleMenu : public QMainWindow {
    Q_OBJECT

public:
    SimpleMenu(QWidget *parent = nullptr);
    ~SimpleMenu();
};
#endif // SIMPLEMENU_H
