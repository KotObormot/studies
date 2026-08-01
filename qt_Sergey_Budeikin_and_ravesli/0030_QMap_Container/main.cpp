#include <QCoreApplication>
#include <QTextStream>
//#include <QMap>

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

    // Создаем QMap, содержащий 2 пары элементов
    QMap<QString, int> items = {{"coins", 5}, {"books", 3}};

    out << "Size = " << items.size() << Qt::endl;

    // С помощью метода insert() добавляем новую пару значений
    items.insert("bottles", 7);
    items.insert("bottles", 12); // Затирает предыдущее значение

    // Получаем все значения словаря и выводим их на экран
    QList<int> values = items.values();  // метод values() возвращает список значений словаря
    out << "\n---------------------------------------\nVALUES:\t";
    foreach (int var, values) {
        out << var << "\t";
    }
    out << Qt::endl;

    // Аналогично выводим все ключи словаря
    QList<QString> keys = items.keys(); // метод keys() возвращает список, содержащий все ключи в словаре
    out << "KEYS:\t";
    for(const QString &key : std::as_const(keys)) {
        /*ошибка c++11 range-loop might detach qt container (qlist) [clazy-range-loop-detach]
         Эта ошибка означает, что ваш цикл for-range (основанный на диапазоне C++11) может спровоцировать неявное копирование (отсоединение/detach) контейнера Qt,
        такого как QList, QVector или QMap.
        В Qt используется механизм Implicit Sharing (копирование при записи / Copy-on-Write).
        Когда вы передаете контейнер Qt в цикл for (auto x : container) по значению,
        компилятор вызывает функции begin() и end().
        Если контейнер не является константным, Qt вызывает свои неконстантные версии этих методов.
        Чтобы гарантировать, что другие копии этого контейнера не изменятся, Qt выполняет глубокое копирование данных в памяти
        (то самое "отсоединение" или detach), даже если вы просто читаете данные. Это приводит к лишней нагрузке на память и процессор.
        Используйте std::as_const (Для Qt 6 / C++17)*/
        out << key << "\t";
    }
    out << Qt::endl << "---------------------------------------" << Qt::endl;

    // Создаем итератор для QMap в Java-стиле
    QMapIterator<QString, int> it(items); // этот итератор может использоваться для итерации по элементам QMap

    out << "PAIRS:" << Qt::endl;

    // С помощью итератора перебираем все элементы QMap
    while(it.hasNext()) {
        it.next();
        //++it.value();
        out << it.key() << "\t" << it.value() << Qt::endl;// метод key() возвращает текущий ключ, а метод value() возвращает текущее значение
    }
    out << "---------------------------------------" << Qt::endl;

    return a.exec();
}
