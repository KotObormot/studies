#include <QFrame>
#include <QSplitter>
#include <QHBoxLayout>
#include "splitter.h"

Splitter::Splitter(QWidget *parent) : QWidget(parent) {

    QHBoxLayout *hbox = new QHBoxLayout(this);

    QFrame *topLeft = new QFrame(this);
    topLeft->setFrameShape(QFrame::StyledPanel);    // установить форму рамки (стилизованная панель QFrame);

    QFrame *topRight = new QFrame(this);
    topRight->setFrameShape(QFrame::StyledPanel);

    QFrame *bottom = new QFrame(this);
    bottom->setFrameShape(QFrame::StyledPanel);

    // Создаем виджет splitterV и добавляем в него два виджета frame:
    QSplitter *splitterH = new QSplitter(Qt::Horizontal, this);
    splitterH->addWidget(topLeft);
    splitterH->addWidget(topRight);

    QSplitter *splitterV = new QSplitter(Qt::Vertical, this);
    // Мы также можем добавить один сплиттер splitterH к другому сплиттеру splitterV:
    splitterV->addWidget(splitterH);
    splitterV->addWidget(bottom);

    // С помощью метода setSizes() устанавливаем размер дочерних виджетов сплиттера:
    QList<int> sizes({50, 100});
    splitterV->setSizes(sizes);
    //splitterH->setSizes(sizes);

    hbox->addWidget(splitterV);
    //hbox->addWidget(splitterH);
}

Splitter::~Splitter() {}
