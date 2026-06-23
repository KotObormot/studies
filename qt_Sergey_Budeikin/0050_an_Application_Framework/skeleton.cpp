#include "skeleton.h"
#include <QToolBar>
#include <QIcon>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QTextEdit>

Skeleton::Skeleton(QWidget *parent) : QMainWindow(parent) {

    QPixmap newpix("://icons/new.png");
    QPixmap openpix("://icons/open.png");
    QPixmap quitpix("://icons/quit.png");

    QAction *quit = new QAction("&Quit", this);

    QMenu *file;
    file = menuBar()->addMenu("&File");
    file->addAction(quit);
    connect(quit, &QAction::triggered, qApp, &QApplication::quit);

    QToolBar *toolbar = addToolBar("Main toolbar");
    toolbar->addAction(QIcon(newpix), "New file");
    toolbar->addAction(QIcon(openpix), "Open file");

    toolbar->addSeparator();

    QAction *quit2 = toolbar->addAction(QIcon(quitpix), "Quit application");
    connect(quit2, &QAction::triggered, qApp, &QApplication::quit);

    QTextEdit *edit = new QTextEdit(this);   // создаем виджет QTextEdit
    setCentralWidget(edit);      // помещаем созданный виджет в центр виджета QMainWindow

    statusBar()->showMessage("Ready");      // показываем в нижней панели приложения сообщение "Ready"
}

Skeleton::~Skeleton() {}
