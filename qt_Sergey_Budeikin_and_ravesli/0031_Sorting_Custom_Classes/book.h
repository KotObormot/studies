//заголовочный файл book.h для нашего пользовательского класса Book (книга):

#ifndef BOOK_H
#define BOOK_H
#include <QString>

class Book {
  public:
    Book(QString auth, QString titl);
    QString getAutthor() const;
    QString getTitle() const;

  private:
    QString author;
    QString title;
};

#endif // BOOK_H
