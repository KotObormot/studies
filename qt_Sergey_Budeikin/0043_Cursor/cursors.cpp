#include "cursors.h"

Cursors::Cursors(QWidget *parent) : QWidget(parent) {
    QFrame *frame1 = new QFrame(this);  // создаем виджет в текущем классe
    frame1->setFrameStyle(QFrame::Box); // устанавливаем рамки фрейма
    //frame1->setCursor(Qt::SizeAllCursor);   // задаем тип курсора SizeAllCursor для фрейма
    //frame1->setCursor(Qt::SizeBDiagCursor);
    frame1->setCursor(Qt::ArrowCursor);     // стандартный курсор (стрелка) по умолчанию

    QFrame *frame2 = new QFrame(this);
    frame2->setFrameStyle(QFrame::Box);
    frame2->setCursor(Qt::WaitCursor);  // задаем тип курсора WaitCursor для фрейма

    QFrame *frame3 = new QFrame(this);
    frame3->setFrameStyle(QFrame::Box);
    frame3->setCursor(Qt::PointingHandCursor);  // задаем тип курсора PointingHandCursor для фрейма

    // Группируем все фреймы в одну строку
    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(frame1, 0, 0);
    grid->addWidget(frame2, 0, 1);
    grid->addWidget(frame3, 0, 2);

    setLayout(grid); // применяем Layout к нашему виджету
}

Cursors::~Cursors() {}
