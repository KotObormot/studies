#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QFileInfo>
#include <QDir>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.
    QTextStream out(stdout);

    out << "Current path\t" << QDir::currentPath() << Qt::endl; // определяем и выводим путь текущего рабочего каталога
    out << "Home path\t" << QDir::homePath() << Qt::endl; // определяем и выводим путь домашнего каталога
    out << "Temporary path\t" << QDir::tempPath() << Qt::endl; // определяем и выводим путь временного каталога
    out << "Root path\t" << QDir::rootPath() << Qt::endl; // определяем и выводим путь корневого каталога

    // EXIT
    return 0;

    return a.exec();
}
