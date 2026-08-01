#include <QCoreApplication>
#include <QTextStream>
#include  <QFile>
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

    // Проверка правильности указания пути к файлу
    if(argc != 2) {
        qWarning("Usage: file_size file."); // Использование: file_size file
        return 1;
    }

    // Для определения размера файла в классе QFileInfo предусмотрен метод size():

    // Имя файла передается в качестве аргумента в нашу программу
    QString fileName = argv[1];

    // Проверяем существование файла
    if(!QFile(fileName).exists()) {
        qWarning("The file doesn't exist."); // если файл не найден, то выводим предупреждение и завершаем работу программы
        return 1;
    }

    // Создаем объект
    QFileInfo fileInfo(fileName); // здесь аргумент == это адрес QString fileName

    // Определяем размер файла с помощью метода size()
    qint64 size = fileInfo.size(); // qint64 - это тип данных, который гарантированно будет 64-битным на всех платформах, поддерживаемых Qt
    /* ошибка value stored to 'size' during its initialization is never read [clang-analyzer-deadcode.deadstores]
     Эта ошибка означает, что вы сохранили значение в переменную size при её создании, но код ни разу не использует это конкретное значение дальше.
    Компилятор Clang считает это «мертвым кодом» (Dead Code) и сообщает об избыточности.*/

    // Выводим результат
    QString str = "The size is: %1 bytes.";
    out << str.arg(size) << Qt::endl;

    return 0;

    return a.exec();
}
