#include "review.h"
#include "./ui_review.h"
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>

Review::Review(QWidget *parent) : QWidget(parent)
                                , ui(new Ui::Review) {
    ui->setupUi(this);

    // Создаем менеджер QGridLayout:
    QGridLayout *grid = new QGridLayout(this);

    // Добавляем вертикальный интервал с помощью метода setVerticalSpacing() и горизонтальный интервал с помощью метода setHorizontalSpacing():
    grid->setVerticalSpacing(15);
    grid->setHorizontalSpacing(10);

    //Эти строки кода создают виджет-метку и помещают её в компоновку. Метод addWidget() имеет пять параметров:
    //  первый параметр — это дочерний виджет, метка в нашем случае;
    //  следующие два параметра — это строка и столбец в сетке компоновки, куда мы помещаем наш виджет;
    //  последние параметры определяют, сколько строк будет занимать текущий виджет (в нашем случае метка будет охватывать только один столбец и одну строку).
    QLabel *title = new QLabel("Title:", this);
    grid->addWidget(title, 0, 0, 1, 1);
    //Метод setAlignment() задает выравнивание метки-заголовка в своей ячейке.
    //По горизонтали — выравнивание по правому краю, по вертикали — выравнивание по центру:
    title->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QLineEdit *editTitle = new QLineEdit(this);
    grid->addWidget(editTitle, 0, 1, 1, 1);
    //grid->addWidget(editTitle, 0, 1, 2, 2);

    QLabel *author = new QLabel("Author:", this);
    grid->addWidget(author, 1, 0, 1, 1);
    author->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QLineEdit *editAuthor = new QLineEdit(this);
    grid->addWidget(editAuthor, 1, 1, 1, 1);

    QLabel *review = new QLabel("Review:", this);
    grid->addWidget(review, 2, 0, 1, 1);
    review->setAlignment(Qt::AlignRight | Qt::AlignTop);

    QTextEdit *textReview = new QTextEdit(this);
    // Виджет QTextEdit помещается в третью (2nd) строку и второй (1st) столбец, он охватывает три строки и один столбец:
    grid->addWidget(textReview, 2, 1, 3, 1);

    setLayout(grid);
}

Review::~Review() {
    delete ui;
}
