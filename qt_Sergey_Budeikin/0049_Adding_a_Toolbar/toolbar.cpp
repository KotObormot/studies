#include "toolbar.h"
#include <QToolBar>
#include <QIcon>
#include <QAction>

Toolbar::Toolbar(QWidget *parent) : QMainWindow(parent) {

    // Данные изображения мы будем использовать в качестве иконок в нашем меню
    QPixmap newpix(":/icons/icons/new.png");
    QPixmap openpix(":/icons/icons/open.png");
    QPixmap quitpix(":/icons/icons/quit.png");

    // Устанавливаем указатель на созданную панель инструментов
    //QToolBar *toolbar = addToolBar("main toolbar");
    QToolBar *toolbar;
    toolbar = addToolBar("main toolbar");

    // добавляем действие "New File" на панель инструментов
    QAction *newf = toolbar->addAction(QIcon(newpix), "New File");

    // добавляем действие "Open File" на панель инструментов
    QAction *openf = toolbar->addAction(QIcon(openpix), "About Qt");

    // добавляем разделитель на панель инструментов
    toolbar->addSeparator();

    // добавляем действие "Quit" на панель инструментов
    QAction *quit = toolbar->addAction(QIcon(quitpix), "Quit Application");

    // В некоторых средах значки меню по умолчанию не отображаются, поэтому мы можем попробовать отключить атрибут Qt::AA_DontShowIconsInMenus
    qApp->setAttribute(Qt::AA_DontShowIconsInMenus, false);

    // signals && slots
    connect(newf, &QAction::triggered, qApp, QApplication::closeAllWindows);
    connect(openf, &QAction::triggered, qApp, QApplication::aboutQt);
    connect(quit, &QAction::triggered, qApp, QApplication::quit);

}

Toolbar::~Toolbar() {}
