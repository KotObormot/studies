#include "cursors.h"

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[]) {

    // Явно прописываем имя приложения для XWayland до старта QApplication
    QCoreApplication::setApplicationName("cursor");

    // Каждое Qt5-приложение (за исключением консольных) должно включать следующую строку
    QApplication a(argc, argv);

    // Должно строго совпадать со значением StartupWMClass и именем .desktop файла
    a.setDesktopFileName("cursor");

    // Оставляем для совместимости с Windows/X11
    a.setWindowIcon(QIcon(":/icon/icon/web.png"));

    Cursors window;

    window.resize(450, 250);
    window.setWindowTitle("Cursor");

    window.show();
    return a.exec();
}
