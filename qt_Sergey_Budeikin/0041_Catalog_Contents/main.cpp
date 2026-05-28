#include <QCoreApplication>
#include <QTextStream>
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

    if(argc != 2) {
        qWarning("Usage: list_dir directory");
        return 1;
    }

    QString directory = argv[1];

    // Создаем объект класса QDir с заданным именем каталога
    QDir dir = directory; // or QDir dir(directory;

    if(!dir.exists()) {
        qWarning("The directory doesn't exist!");
        return 1;
    }

    // Метод setFilter() определяет тип файлов, которые должны быть возвращены методом entryInfoList()
    dir.setFilter(QDir::Files | QDir::AllDirs);

    // Метод setSorting() задает порядок сортировки, используемый методом entryInfoList()
    dir.setSorting(QDir::Size | QDir::Reversed);

    // Метод entryInfoList() возвращает список объектов QFileInfo для всех файлов и папок в каталоге, отфильтрованных и упорядоченных соответствующими методами
    QFileInfoList list = dir.entryInfoList();

    // Проходимся по списку и определяем максимальный размер имени файла
    int max_size(0);

    foreach(QFileInfo finfo, list) {
        QString name = finfo.fileName();
        int size = name.size();
        if(size > max_size) {
            max_size = size;
        }
    }

    // Добавляем дополнительные два пробела к длине столбца
    int len = max_size + 2;

    // Выводим имена столбцов
    out << QString("Filename").leftJustified(len).append("Bytes") << Qt::endl;
    // метод leftJustified() возвращает строку заданного размера, выравненную по левому краю и дополненную символом заполнения (по умолчанию пробел) справа

    // Просматриваем список файлов и выводим их названия и размеры.
    //Первый столбец выравнивается по левому краю и заполняется пробелами по мере необходимости, затем добавляется второй столбец
    for(int i = 0; i < list.size(); ++i) {
        QFileInfo fileInfo = list.at(i);
        QString str = fileInfo.fileName().leftJustified(len);
        str.append(QString("%1").arg(fileInfo.size()));
        out << str << Qt::endl;
    }

    // EXIT
    return 0;

    return a.exec();
}
