#include <QCoreApplication>
#include <QTextStream>
#include <QList>
#include <algorithm>
/*main.cpp:: Included header algorithm is not used directly (fix available)
 *
 * Эта ошибка (точнее, предупреждение) означает, что в файле main.cpp подключена библиотека #include <algorithm>,
но ваш код не вызывает напрямую ни одну функцию из неё (например, std::sort, std::find, std::min).
Предупреждение выдает статический анализатор кода (обычно Clang-Tidy или Cliche), встроенный в Qt Creator.
*/

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

    QList<QString> authors = {"Balzac", "Tolstoy", "Gulbranssen", "London"};

    out << authors.size() << " autors: ";

    for(const QString &author : authors) {  // Добавлено const и &
        out << author << ", ";
        /*почему qt6 показывает missing reference in range-for with non trivial type (qstring) [clazy-range-loop-reference]
         Это предупреждение выдает анализатор Clazy, встроенный в Qt Creator.
         Оно означает, что в цикле for вы копируете тяжелый объект QString вместо передачи его по ссылке.
        Почему это происходит
        Конструкция for (QString s : list) заставляет программу создавать копию строки на каждой итерации.
        Хотя в Qt используется механизм "копирования при записи" (implicit sharing),
        создание копии все равно увеличивает счетчик ссылок и загружает процессор лишними операциями.
        Для тяжелых и нетривиальных типов данных (таких как QString, QByteArray, QVariant) это считается неоптимальным.
        Как исправить
        Добавьте константную ссылку const &. Это исключит копирование и защитит данные от случайного изменения.*/
    }
    out << Qt::endl;

    out << "\n------------------------------------------\n" << Qt::endl;

    // оператор сдвига
    authors << "Galsworthy" << "Sienkiewicz";
    // сортировка
    std::sort(authors.begin(), authors.end());
    out << "The new sorted list of authors:" << Qt::endl;
    for(int i = 0; i < authors.size(); ++i) {
        out << i << ") " << authors.at(i) << Qt::endl;
    }
    out << Qt::endl;

    return a.exec();
}
