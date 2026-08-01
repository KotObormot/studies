#include <QFrame>
#include <QSplitter>
#include <QHBoxLayout>
#include "splitter.h"

Splitter::Splitter(QWidget *parent) : QWidget(parent) {

    QHBoxLayout *hbox = new QHBoxLayout(this);

    QFrame *topLeft = new QFrame(this);
    topLeft->setFrameShape(QFrame::StyledPanel); // Форма рамки :: Стилизованная панель

    QFrame *topRight = new QFrame(this);
    topRight->setFrameShape(QFrame::StyledPanel);

    QFrame *bottom = new QFrame(this);
    bottom->setFrameShape(QFrame::StyledPanel);

    // Создаем виджет splitterH и добавляем в него два виджета frame:
    QSplitter *splitterH = new QSplitter(Qt::Horizontal, this);
    splitterH->addWidget(topLeft);
    splitterH->addWidget(topRight);

    QSplitter *splitterV = new QSplitter(Qt::Vertical, this);
    //Мы также можем добавить один сплиттер к другому сплиттеру:
    splitterV->addWidget(splitterH);
    splitterV->addWidget(bottom);

    //С помощью метода setSizes() устанавливаем размер дочерних виджетов сплиттера:
    QList<int> sizes({50, 100});
    splitterV->setSizes(sizes);

    hbox->addWidget(splitterV);
}

Splitter::~Splitter() {}
