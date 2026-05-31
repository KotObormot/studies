#include "widget.h"

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[]) {

    // ХИТРОСТЬ: Явно прописываем имя приложения для XWayland до старта QApplication
    QCoreApplication::setApplicationName("simple_qwidget");

    // Каждое Qt5-приложение (за исключением консольных) должно включать следующую строку
    QApplication a(argc, argv);

    // Должно строго совпадать со значением StartupWMClass и именем .desktop файла
    a.setDesktopFileName("simple_qwidget");

    // Оставляем для совместимости с Windows/X11
    a.setWindowIcon(QIcon(":/icon/icon/web.png"));

    // Главный виджет, который представляет окно нашей программы
    Widget window;

    // NAMES
    QString name = "Simple example";
    QString toolTipName("QWidget");

    window.resize(750, 450);    // изменяем размер виджета в пикселях
    window.move(300, 300);
    window.setWindowTitle(name); // устанавливаем заголовок для главного окна
    window.setToolTip(toolTipName);      // устанавливаем всплывающую подсказку для виджета

    // !!! СТРОКУ НИЖЕ НУЖНО УДАЛИТЬ ИЛИ ЗАКОММЕНТИРОВАТЬ !!!
    //window.setWindowIcon(QIcon(":/icon/icon/web.png")); //Для отображения иконки мы используем метод setWindowIcon() и класс QIcon. Иконка представляет собой небольшой .png-файл, расположенный в текущем рабочем каталоге

    window.show();  // выводим виджет на экран

    return a.exec();    // С помощью метода exec() запускаем основной цикл нашей программы
}
