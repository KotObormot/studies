//реализация класса Book (у нас есть два геттеры для доступа к элементам класса):

#include "book.h"

Book::Book(QString auth, QString titl) {
    author = auth;
    title = titl;
}

QString Book::getAutthor() const {
    return author;
}

QString Book::getTitle() const {
    return title;
}
