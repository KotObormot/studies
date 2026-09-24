#include <QList>
#include <QString>
#include <QFontMetrics>
#include "progressline.h"

ProgressLine::ProgressLine(QFrame *parent, int min, int max, int points, int orange_zone, int red_zone)
    : QFrame(parent)
    , m_value(min)
    , m_min(min)
    , m_max(max)
    , m_count(points)
    , m_orange_zone(orange_zone)
    , m_red_zone(red_zone) {
    // Инициализируем родительский класс и переменные-члены
}

void ProgressLine::paintEvent([[maybe_unused]] QPaintEvent *e) {
    doPainting();       // делегируем отрисовку методу doPainting
}

void ProgressLine::doPainting() {

    QPainter painter(this);     // создаем объект QPainter

    qreal widgetWidth = this->width() - 2; // вычисляем ширину виджета и отнимаем 2 пикселя для корректной отрисовки крайних вертикальных линий

    QList<QString> numbers; // создаем список строк, в котором будем хранить числа в формате строки
    // Заполняем список числами, вычисляем их в зависимости от установленного минимального, максимального значения и количества точек
    for(int i = 0; i < m_count; i++) {

        QString temp;
        int numerator = m_max - m_min;
        int denominator = m_count - 1;

        if(denominator != 0) {
            temp.setNum(m_min + i * numerator / denominator);
        }

        numbers.push_back(temp);
    }

    QFont font("Times New Roman", M_FONT_SIZE);         // шрифт для чисел
    QFontMetrics metrics(font);                         // измеритель шрифта

    for(int pos = 0; pos < numbers.size(); pos++) {

        qreal textMid = metrics.horizontalAdvance(numbers.at(pos)) / 2.0;   // вычисляем средину строки в пикселях для каждого числа из списка
        qreal step = widgetWidth / (numbers.size() - 1) * (pos);            // вычисляем позицию для отрисовки линий
        painter.drawLine(step, 0, step, M_LINE_HEIGHT);                     // рисуем вертикальные линии
        painter.setFont(font);                                              // установим шрифт для чисел

        // Рисуем числа для всех линий кроме первой и последней
        if(pos != 0 && pos != numbers.size() - 1) {
            painter.drawText(step - textMid
                             , M_FONT_SIZE + M_LINE_HEIGHT + M_PIXELS_BETWEEN_LINE_AND_TEXT
                             , numbers.at(pos));
        }
    }

    qreal one_point_width = widgetWidth / (m_max - m_min);          // вычисляем ширину в пикселях одного пункта m_value
    painter.setPen(QPen(QBrush(QColor("grey")), 1, Qt::SolidLine)); // установим перо для контура прямоугольника
    painter.setOpacity(0.5);                                        // установим прозрачность прямоугольника

    if(m_value < m_orange_zone) {                                   // Рисуем прямоугольник для зеленой зоны
        painter.setBrush(QColor("light green"));
        painter.drawRect(0, 0, one_point_width * m_value - one_point_width * m_min, 30);
    } else if(m_value < m_red_zone) {                                // Рисуем прямоугольник для оранжевой зоны
        painter.setBrush(QColor("light green"));
        painter.drawRect(0, 0, one_point_width * m_orange_zone - one_point_width * m_min, 30);
        painter.setBrush(QColor("yellow"));
        painter.drawRect(one_point_width * m_orange_zone - one_point_width * m_min, 0, one_point_width * m_value - one_point_width * m_orange_zone, 30);
    } else {                                                         // Рисуем прямоугольник для красной зоны
        painter.setBrush(QColor("light green"));
        painter.drawRect(0, 0, one_point_width * m_orange_zone - one_point_width * m_min, 30);
        painter.setBrush(QColor("orange"));
        painter.drawRect(one_point_width * m_orange_zone - one_point_width * m_min, 0, one_point_width * m_value - one_point_width * m_orange_zone, 30);
        painter.setBrush(QColor("red"));
        painter.drawRect(one_point_width * m_red_zone - one_point_width * m_min, 0, one_point_width * m_value - one_point_width * m_red_zone, 30);
    }
}

// Сеттер для установки m_value
void ProgressLine::setValue(int value) {
    if(value >= m_min && value <= m_max) {
        m_value = value;
    }

    this->repaint();                // перерисовываем виджет при каждом изменения значения
}
