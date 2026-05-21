#include <QCoreApplication>
#include <QTextStream>
#include <QList>
#include <algorithm>
#include "book.h"

//compareByTitle() — это функция сравнения, используемая алгоритмом сортировки:
bool compareByTitle(const Book &b1, const Book &b2) {
    return b1.getTitle() < b2.getTitle();
}

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

    //создадим несколько объектов класса Book
    QList<Book> books = {
        Book("Jack London", "The Call of the Wild"),
        Book("Honoré de Balzac", "Father Goriot"),
        Book("Leo Tolstoy", "War and Peace"),
        Book("Gustave Flaubert", "Sentimental education"),
        Book("Guy de Maupassant", "Une vie"),
        Book("William Shakespeare", "Hamlet")
    };

    //отсортируем их с помощью алгоритма std::sort()
    std::sort(books.begin(), books.end(), compareByTitle);

    //result
    out << "OUR BOOKS:" << Qt::endl;
    for(const auto &book : books) {
        out << book.getAutthor() << "\t \t" << book.getTitle() << Qt::endl;
    }
    out << Qt::endl;

    return a.exec();
}
