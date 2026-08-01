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
    QTextStream out(stdout);

    // Программа принимает 2 параметра
    if(argc != 3) {
        qWarning("Usage: copyfile source destination");     // если параметров нет, то выводится предупреждение
        return 1;
    }

    // Из аргументов командной строки программы мы получаем имя исходного файла
    QString source = argv[1];

    // Проверяем наличие исходного файла
    if(!QFile(source).exists()) {
        qWarning("The source file does not exist");    // если файл не найден, то выводим предупреждение и завершаем выполнение
        return 1;
    }

    // Получаем имя файла назначения
    QString destin = argv[2];

    // Копируем исходный файл в файл назначения
    QFile::copy(source, destin);

    // Завершаем код
    return 0;

    return a.exec();
}
