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
    /*out << "Hello world!" << Qt::endl;*/

    // Создаем объект
    QFile file("colours.txt");

    // С помощью метода open() открываем файл в режиме чтения
    if(!file.open(QIODevice::ReadOnly)) {
        qWarning("Cannot open the file for reading!"); // если файл не найден, то выводим предупреждение и завершаем выполнение программы
        return 1;
    } /*else {
        qWarning("Success :-)");
    }*/

    // Создаем входящий поток, из которого будут считываться данные, и связываем его с нашим файлом (ссылкой)
    QTextStream in(&file);

    // Считываем файл строка за строкой
    while(!in.atEnd()) {        // метод atEnd() возвращает true, если в потоке больше нет данных для чтения
        QString line = in.readLine(); // метод readLine() считывает одну строку из потока
        out << line << Qt::endl;
    }

    // Закрываем файл
    file.close();

    // Завершаем код
    return 0;

    return a.exec();
}
