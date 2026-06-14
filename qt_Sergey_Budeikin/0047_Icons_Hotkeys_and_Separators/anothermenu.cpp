#include "anothermenu.h"
#include <QMenu>
#include <QMenuBar>

AnotherMenu::AnotherMenu(QWidget *parent) : QMainWindow(parent) {

    // Данные изображения мы будем использовать в качестве иконок в нашем меню
    QPixmap newpix(":/new/prefix1/quit.png");
    QPixmap openpix(":/new/prefix1/open.png");
    QPixmap quitpix(":/new/prefix1/new.png");

    // Здесь в качестве первых аргументов мы используем конструкторы класса QAction
    QAction *newa = new QAction(newpix, "&New", this);
    QAction *open = new QAction(openpix, "&Open", this);
    QAction *quit = new QAction(quitpix, "&Quit", this);

    // А здесь мы задаем сочетание горячих клавиш CTRL+Q, которое будет выполнять действие Quit (Выход)
    newa->setShortcut(tr("CTRL+N"));
    open->setShortcut(tr("CTRL+O"));
    quit->setShortcut(tr("CTRL+Q"));

    // Создаем объект класса QMenu (меню) (с подчеркнутой литерой F)
    QMenu *file;
    file = menuBar()->addMenu("&File");

    // добавляем действие "New"
    file->addAction(newa);

    // добавляем действие "Open"
    file->addAction(open);

    // устанавливаем разделитель
    file->addSeparator();

    // добавляем действие "Quit"
    file->addAction(quit);

    // В некоторых средах значки меню по умолчанию не отображаются, поэтому мы можем попробовать отключить атрибут Qt::AA_DontShowIconsInMenus
    //qApp->setAttribute(Qt::AA_DontShowIconsInMenus, false);
    // без разницы, в Linux значьки все равно не отображаются :-))

    connect(newa, &QAction::triggered, qApp, &QApplication::closeAllWindows);
    connect(open, &QAction::triggered, qApp, &QApplication::aboutQt);
    connect(quit, &QAction::triggered, qApp, &QApplication::quit);
}

AnotherMenu::~AnotherMenu() {}
