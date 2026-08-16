#include "adaptivelineargradient.h"

AdaptiveLinearGradient::AdaptiveLinearGradient(QWidget *parent) : QWidget(parent) {
    // Настраиваем цвета градиента один раз в конструкторе. В paintEvent просто используем готовое поле класса.
    // 1. Настраиваем геометрию и цвета градиента ОДИН раз при создании виджета
    m_gradVer.setStart(0, 20);
    m_gradVer.setFinalStop(0, 110);

    m_gradVer.setColorAt(0.1, Qt::black);
    m_gradVer.setColorAt(0.5, Qt::yellow);
    m_gradVer.setColorAt(0.9, Qt::blue);
}

//AdaptiveLinearGradient::~AdaptiveLinearGradient() {}

void AdaptiveLinearGradient::paintEvent([[maybe_unused]] QPaintEvent *e) {
    // 2. QPainter по-прежнему создаем на стеке — это стандарт Qt
    QPainter painter(this);

    // 3. Просто передаем уже готовый и настроенный градиент.
    // Никаких выделений памяти и лишних вычислений в этом методе больше нет!
    painter.fillRect(20, 20, 300, 90, m_gradVer);
}
