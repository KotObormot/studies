#include "iridescentlingrad.h"

IridescentLinGrad::IridescentLinGrad(QWidget *parent) : QWidget(parent) {
    // В конструкторе мы настраиваем таймер и связываем его со специальной функцией (лямбдой), которая увеличивает смещение и заставляет виджет перерисоваться.
    // 1. Базовая настройка адаптивного градиента
    m_gradVer.setCoordinateMode(QGradient::ObjectMode);     // Переводим градиент в режим относительных координат объекта
    // Теперь (0, 0) — это левый верхний угол прямоугольника, а (0, 1) — левый нижний.

    // КРИТИЧЕСКИ ВАЖНО: заставляем Qt автоматически зацикливать градиент
    m_gradVer.setSpread(QGradient::RepeatSpread);

    // Задаем цвета жестко ОДИН раз. Они больше не будут путаться местами.
    m_gradVer.setColorAt(0.0, Qt::black);
    m_gradVer.setColorAt(0.33, Qt::yellow);
    m_gradVer.setColorAt(0.66, Qt::blue);
    m_gradVer.setColorAt(1.0, Qt::black); // Замыкаем в черный, чтобы не было стыка

    // 2. Настраиваем таймер (~60 FPS для идеальной плавности)
    connect(&m_timer, &QTimer::timeout, this, [this]() {
        m_offset += 0.005;       //Скорость анимации
        if(m_offset > 1.0) {
            m_offset = 0.0;     // Сбрасываем при полном цикле
        }

        this->update();         // Запрашиваем перерисовку виджета (вызов paintEvent)
    });

    m_timer.start(16);          // Запускаем таймер
}

//IridescentLinGrad::~IridescentLinGrad() {}

void IridescentLinGrad::paintEvent([[maybe_unused]] QPaintEvent *e) {

    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);

    // Двигаем сам вектор градиента вниз по оси Y
    m_gradVer.setStart(0.0, 0.0 + m_offset);
    m_gradVer.setFinalStop(0.0, 1.0 + m_offset);

    // 4. Отрисовка
    painter.fillRect(0, 0, this->width(), this->height(), m_gradVer);
}

