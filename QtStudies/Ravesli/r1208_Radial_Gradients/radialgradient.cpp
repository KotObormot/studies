#include "radialgradient.h"

RadialGradient::RadialGradient(QWidget *parent) : QWidget(parent) {
    m_gradRad.setCoordinateMode(QGradient::ObjectMode);
    m_gradRad.setSpread(QGradient::RepeatSpread);           // КРИТИЧЕСКИ ВАЖНО: заставляем Qt автоматически зацикливать градиент

    // Центр круга — строго посередине виджета (0.5, 0.5)
    // Радиус равен 0.5 (круг аккуратно впишется в границы виджета)
    m_gradRad.setCenter(0.5, 0.5);
    m_gradRad.setFocalPoint(0.5, 0.5);                      // (Опционально) Можно сместить фокусную точку, откуда исходят лучи:

    // Задаем цвета жестко ОДИН раз. Они больше не будут путаться местами.
    m_gradRad.setColorAt(0.0, Qt::black);
    m_gradRad.setColorAt(0.33, Qt::red);
    m_gradRad.setColorAt(0.66, Qt::blue);
    m_gradRad.setColorAt(1.0, Qt::black);

     // 2. Настраиваем таймер (~60 FPS для идеальной плавности)
    connect(&m_timer, &QTimer::timeout, this, [this]() {
        //В конструкторе мы меняем фиксированный шаг на переменную m_speed
        m_offset += /*0.005*/m_speed;                                //Скорость анимации    // Прибавляем текущую скорость

        //при отрицательной скорости волны могут бежать внутрь, поэтому делаем циклическую проверку для m_offset в обе стороны
        if(m_offset > 1.0) {
            m_offset /*= 0.0*/ -= 1.0;                              // Корректный сброс offset для движения в обе стороны
        } else if(m_offset < 0.0) {
            m_offset += 1.0;
        }

        this->update();                                 // Запрашиваем перерисовку виджета (вызов paintEvent)
    });

    m_timer.start(16);                                  // Запускаем таймер
}

//RadialGradient::~RadialGradient() {}

void RadialGradient::paintEvent([[maybe_unused]] QPaintEvent *e) {
    QPainter painter(this);

    // Включаем сглаживание, чтобы круги отрисовывались плавно и красиво
    // v.1.3. // Включаем сглаживание как для графики, так и для текста
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);      // Этот флаг убирает «лесенку» по краям букв, делая текст идеально гладким.

    // вместо смещения стартовых точек мы будем плавно изменять радиус окружности.
    // Динамически меняем базовый радиус (например, от 0.1 до 1.1)
    // Чем меньше стартовое число, тем ближе к центру зарождаются круги
    m_gradRad.setRadius(0.1 + m_offset);

    // 4. Отрисовка на весь экран
    painter.fillRect(0, 0, this->width(), this->height(), m_gradRad);

    // v.1.3 // 2. Настройка шрифта
    QFont font("Arial", 16, QFont::Bold);           // Установили красивый, жирный шрифт Arial.
    painter.setFont(font);

    // Сделаем текст белым, чтобы он выделялся
    painter.setPen(Qt::white);

    // 3. Форматируем строку со значением скорости
    // Умножаем на 1000 для наглядности (чтобы видеть целые числа вместо 0.005)
    // Форматирует вывод переменной m_speed, округляя её до одного знака после запятой ('f', 1), чтобы цифры на экране не мерцали из-за длинного хвоста дроби.
    QString speedText = QString("Speed: %1").arg(m_speed * 1000, 0, 'f', 1);

    // 4. Отрисовка текста в левом верхнем углу с небольшим отступом (20 пикселей)
    painter.drawText(20, 40, speedText);

    // Альтернативный вариант: если захотите отцентрировать текст строго по центру окна:
    // painter.drawText(this->rect(), Qt::AlignCenter, speedText);
}

// Новый метод: перехватывает вращение колесика мыши
void RadialGradient::wheelEvent(QWheelEvent *event) {
    // event->angleDelta().y() возвращает положительное значение при прокрутке вверх/вперед
    // и отрицательное — при прокрутке вниз/назад. Обычно один шаг равен 120 единицам.
    double delta = event->angleDelta().y() / 120.0;

    // Изменяем скорость. Один шаг колесика изменит её на 0.001
    m_speed += delta * 0.001;

    // Ограничиваем скорость разумными рамками (например, от -0.05 до 0.05)
    // чтобы анимация не становилась слишком бешеной или неконтролируемой
    if (m_speed > 0.05) m_speed = 0.05;
    if (m_speed < -0.05) m_speed = -0.05;

    // Принимаем событие, сообщая системе, что мы его обработали
    event->accept();
}

