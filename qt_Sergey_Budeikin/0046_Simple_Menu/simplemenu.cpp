#include "simplemenu.h"

SimpleMenu::SimpleMenu(QWidget *parent) : QMainWindow(parent) {
    // Создаем объект класса QAction (действие) с названием пункта меню "Quit" (подчеркнута литера Q)
    QAction *quit = new QAction("&Quit", this);

    // Создаем объект класса QMenu (меню) (с подчеркнутой литерой F)
    QMenu *file;
    file = menuBar()->addMenu("&File");

    // Помещаем действие "Quit" (Выход) в меню с помощью метода addAction()
    file->addAction(quit);

    // Когда мы выбираем в меню опцию "Quit", то приложение сразу же завершает свое выполнение
    //connect(quit, &QAction::triggered, qApp, QApplication::quit);
    connect(quit, &QAction::triggered, qApp, &QApplication::quit);

    QAction *info = new QAction("&Info", this);
    QMenu *aboutQt;
    aboutQt = menuBar()->addMenu("About&Qt");
    aboutQt->addAction(info);
    connect(info, &QAction::triggered, qApp, &QApplication::aboutQt);
}

SimpleMenu::~SimpleMenu() {}
