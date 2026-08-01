#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QFileInfo>
#include <QDateTime>

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

    if(argc != 2) {
        qWarning("Usage: file_times file");
        return 1;
    }

    QString fileName = argv[1];

    // Создаем объект класса QFileInfo. В качестве параметра используем имя файла из аргумента командной строки
    QFileInfo fileInfo(fileName);

    // Определяем дату и время последнего чтения файла
    QDateTime lastRead = fileInfo.lastRead();

    // Определяем дату и время последнего изменения файла
    QDateTime lastMod = fileInfo.lastModified();

    // PRINT
    out << "Last read\t" << lastRead.toString() << Qt::endl;
    out << "Last modified\t" << lastMod.toString() << Qt::endl;

    // EXIT
    return 0;

    return a.exec();
}
