#include <QtGui>
#include "burning.h"
#include "widget.h"

const int PANEL_HEIGHT = 30;

Widget::Widget(QWidget *parent) : QFrame(parent) {

    m_parent = parent;
    setMinimumHeight(PANEL_HEIGHT);
}

// Рисование пользовательского виджета делегируется методу drawWidget():
void Widget::paintEvent([[maybe_unused]] QPaintEvent *e) {

    QPainter qp(this);
    drawWidget(qp);

    QFrame::paintEvent(e);
}

void Widget::drawWidget(QPainter &qp) {

    // Данные числа используются для отображения масштаба виджета:
    QString num[] = {"75", "150", "225", "300", "375", "450", "525", "600", "675"};
    // Получаем ширину виджета.

    //Стоит отметить, что ширина пользовательского виджета является динамической. Она может быть изменена пользователем (например, при изменении размеров окна):
    int asize = sizeof(num) / sizeof(num[1]);

    QColor redColor(255, 175, 175);
    QColor yellowColor(255, 255, 184);

    int width = size().width();

    // Получаем значение переменной cur_width:
    Burning *burn = (Burning *) m_parent;
    int cur_width = burn->getCurrentWidth();

    int step = (int) qRound((double)width / DIVISIONS);

    //Используем переменную width для выполнения преобразований между значениями шкалы и размерами пользовательского виджета:
    int till = (int) ((width / MAX_CAPACITY) * cur_width);
    int full = (int) ((width / MAX_CAPACITY) * FULL_CAPACITY);

    if(cur_width >= FULL_CAPACITY) {

        qp.setPen(yellowColor);
        qp.setBrush(yellowColor);
        qp.drawRect(0, 0, full, 30);
        // Данные линии рисуют красный прямоугольник, указывающий на перепрожиг:
        qp.setPen(redColor);
        qp.setBrush(redColor);
        qp.drawRect(full, 0, till - full, PANEL_HEIGHT);

    } else if(till > 0) {

        qp.setPen(yellowColor);
        qp.setBrush(yellowColor);
        qp.drawRect(0, 0, till, PANEL_HEIGHT);
    }

    QColor grayColor(90, 80, 60);
    qp.setPen(grayColor);

    for(int i = 1; i <= asize; i++) {
        // Рисуем небольшие вертикальные линии:
        qp.drawLine(i * step, 0, i * step, LINE_WIDTH);
        QFont newFont = font();
        newFont.setPointSize(7);
        setFont(newFont);

        // Рисуем числа шкалы. Чтобы точно расположить числа, мы должны получить ширину строки:
        QFontMetrics metrics(font());

        //int w = metrics.width(num[i - 1]);
        int w = metrics.horizontalAdvance(num[i - 1]);
        qp.drawText(i * step - w / 2, DISTANCE, num[i - 1]);
    }
}
