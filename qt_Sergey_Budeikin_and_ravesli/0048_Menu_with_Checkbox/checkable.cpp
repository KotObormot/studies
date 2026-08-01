#include "checkable.h"
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
//#include <iostream>

Checkable::Checkable(QWidget *parent) : QMainWindow(parent) {

    // Создаем действие (пункт) "View statusbar" в меню
    viewSt = new QAction("&View statusbar", this);

    // Делаем так, чтобы этот пункт меню можно было отметить галочкой
    viewSt->setCheckable(true);

    // Делаем этот пункт меню отмеченным галочкой по умолчанию
    viewSt->setChecked(true);

    QMenu *file;
    file = menuBar()->addMenu("&File");
    file->addAction(viewSt);

    file->addSeparator();

    quit = new QAction("&Quit", this);
    file->addAction(quit);

    statusBar()->showMessage("Status bar1"); // Панель состояния (status bar)

    connect(viewSt, &QAction::triggered, this, &Checkable::toggleStatusbar);
    connect(quit, &QAction::triggered, qApp, &QApplication::quit);
}

void Checkable::toggleStatusbar() {
    // Определяем, установлен ли флажок для элемента меню, и, исходя из этого, скрываем или показываем строку состояния
//    std::cout << viewSt->isChecked() << std::endl;
    if(viewSt->isChecked()) {
        statusBar()->show();
        statusBar()->showMessage("Status bar2");
    } else {
        statusBar()->hide();
    }
}

Checkable::~Checkable() {}
