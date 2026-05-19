#include <QCoreApplication>
#include <QTextStream>
#include <QSet>

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

    QSet<QString> cols1 = {"yellow", "red", "blue"};
    QSet<QString> cols2 = {"blue", "pink", "orange"};

    out << "There are " << cols1.size() << " colors in the first set:" << Qt::endl;
        foreach (const QString &var, cols1) {
        out << " - " << var << Qt::endl;
    }
    out << Qt::endl;

    cols1.insert("brown");
    out << "Now, there are " << cols1.size() << " colors in the first set:" << Qt::endl;
    for(const QString &val : cols1) {
        out << " - " << val << Qt::endl;
    }
    out << Qt::endl;

    int colsOneSize = cols1.size();

    out << "There are " << cols2.size() << " colors in the second set:" << Qt::endl;
    foreach (const QString &var, cols2) {
        out << " - " << var << Qt::endl;
    }
    out << Qt::endl;

    // Метод unite() выполняет объединение двух наборов
    cols1.unite(cols2);
    out << "There are " << cols1.size() << " (but not " << colsOneSize + cols2.size() << ") colors in the united set:" << Qt::endl;

    // Перебираем все элементы набора cols1 и выводим их на экран
    for(const QString &val : cols1) {
        out << " > " << val << Qt::endl;
    }
    out << Qt::endl;

    // Создаем отдельный список из набора элементов cols1 для их сортировки
    QList<QString> lcols = cols1.values(); // метод values() возвращает новый QList, содержащий элементы набора
    std::sort(lcols.begin(), lcols.end());

    out << "*********************" << Qt::endl;
    out << "Sorted:" << Qt::endl;

    /*for(const QString &val : lcols) {
        out << val << Qt::endl;
    }*/
    foreach (const QString &var, lcols) {
        out << " -> " << var << Qt::endl;
    }
    out << Qt::endl;

    return a.exec();
}
