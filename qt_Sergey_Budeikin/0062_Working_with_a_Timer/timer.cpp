#include "timer.h"
#include <QHBoxLayout>
#include <QTime>

Timer::Timer(QWidget *parent) : QWidget(parent) {

    QHBoxLayout *hbox = new QHBoxLayout(this);
    hbox->setSpacing(5);

    // Для отображения времени мы используем виджет-метку:
    label = new QLabel("", this);
    hbox->addWidget(label, 0, Qt::AlignLeft | Qt::AlignTop);

    // Запускаем таймер:
    QTime qtime = QTime::currentTime();
    QString stime = qtime.toString();
    label->setText(stime);

    // при этом каждые 1000 мс генерируется событие таймера
    startTimer(1000);
}

// Для работы с событиями таймера необходимо переопределить метод timerEvent():
void Timer::timerEvent([[maybe_unused]] QTimerEvent *event) {

    //Q_UNUSED(event);

    QTime qtime = QTime::currentTime();
    QString stime = qtime.toString();
    label->setText(stime);
}

Timer::~Timer() {}
