#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QFileInfo>

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

    // Программа принимает 1 параметр
    if(argc != 2) {
        qWarning("Usage: owner file");
        return 1;
    }

    // Из аргументов командной строки программы мы получаем имя файла
    QString filename = argv[1];

    // Проверяем наличие исходного файла
    if(!QFile(filename).exists()) {
        qWarning("The file does not exist");    // если файл не найден, то выводим предупреждение и завершаем выполнение
        return 1;
    }

    // Создаем объект класса QFileInfo. В качестве параметра используем имя файла из аргумента командной строки
    QFileInfo fileinfo(filename);

    // Определяем основную группу файла
    QString group = fileinfo.group();

    // Определяем владельца файла
    QString owner = fileinfo.owner();
    qint64 ownerID = fileinfo.ownerId();

    // print results
    out << "Group\t" << group << Qt::endl;
    out << "Owner\t" << owner << Qt::endl;
    out << "ID\t" << ownerID << Qt::endl;

    // end
    return 0;

    return a.exec();
}
