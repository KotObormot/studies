#include <QCoreApplication>
#include <QTextStream>
#include <QFile>

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

    /*QTextStream out(stdout);*/

     // Создаем объект класса QFile и связываем его с указанным именем файла
    /*QString filename = "distros.txt";
    QFile file(filename);*/
    QFile file("distros1.txt");

    // Открываем файл в режиме "Только для записи"
    if(file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);             // поток записываемых данных направляем в файл

        // Для записи данных в файл используем оператор <<
        out << "Xubuntu" << Qt::endl;
        out << "Arch" << Qt::endl;
        out << "Debian" << Qt::endl;
        out << "Redhat" << Qt::endl;
        out << "Slackware" << Qt::endl;
    } /*else {
        qWarning("Could not open file");    // если айл не открыт, то он создается по умолчанию
        return 1;
    }*/

    // Закрываем файл
    file.close();

    // завершаем код
    return 0;

    return a.exec();
}
