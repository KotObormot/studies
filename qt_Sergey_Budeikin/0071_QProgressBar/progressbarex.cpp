#include <QTimer>
#include <QGridLayout>
#include "progressbarex.h"

ProgressBarEx::ProgressBarEx(QWidget *parent) : QWidget(parent) {

    progress = 0;
    //QTimer используется для управления виджетом QProgressBar:
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ProgressBarEx::updateBar);

    QGridLayout *grid = new QGridLayout(this);
    grid->setColumnStretch(2, 1);

    // Создадим экземпляр QProgressBar. Минимальное и максимальное значения по умолчанию указываются в диапазоне от 0 до 100:
    pBar = new QProgressBar();
    grid->addWidget(pBar, 0, 0, 1, 3);

    startBttn = new QPushButton("Sart", this);
    connect(startBttn, &QPushButton::clicked, this, &ProgressBarEx::startTimer);
    grid->addWidget(startBttn, 1, 0, 1, 1);

    stopBttn = new QPushButton("Stop", this);
    connect(stopBttn, &QPushButton::clicked, this, &ProgressBarEx::stopTimer);
    grid->addWidget(stopBttn, 1, 1);
}

ProgressBarEx::~ProgressBarEx() {}

void ProgressBarEx::startTimer() {

    if(progress >= MAX_VALUE) {
        progress = 0;
        pBar->setValue(0);
    }

    // В зависимости от состояния индикатора выполнения кнопки могут быть включены или выключены. Эта возможность реализуется с помощью метода setEnabled():
    if(!timer->isActive()) {
        startBttn->setEnabled(false);
        stopBttn->setEnabled(true);
        timer->start(DELAY);
    }
}

void ProgressBarEx::stopTimer() {
    if(timer->isActive()) {
        startBttn->setEnabled(true);
        stopBttn->setEnabled(false);
        timer->stop();
    }
}

void ProgressBarEx::updateBar() {
    // Ход выполнения операции сохраняется в переменной progress. Метод setValue() обновляет текущее значение индикатора выполнения:
    progress++;
    if(progress <= MAX_VALUE) {
        pBar->setValue(progress);
    } else {
        timer->stop();
        startBttn->setEnabled(true);
        stopBttn->setEnabled(false);
    }
}
