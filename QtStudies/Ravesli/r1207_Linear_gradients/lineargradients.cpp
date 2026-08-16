#include <QPainter>
#include "lineargradients.h"

LinearGradients::LinearGradients(QWidget *parent) : QWidget(parent) {}

LinearGradients::~LinearGradients() {}

void LinearGradients::paintEvent([[maybe_unused]] QPaintEvent *e) {
    doPainting();
}

void LinearGradients::doPainting() {

    QPainter *painter = new QPainter(this);

/* // В Qt многие классы отрисовки, включая градиенты, являются объектами-значениями и обычно создаются на стеке, а не в куче.

      QLinearGradient *gradVer = new QLinearGradient(0, 20, 0, 110);

    gradVer->setColorAt(0.1, Qt::black);
    gradVer->setColorAt(0.5, Qt::yellow);
    gradVer->setColorAt(0.9, Qt::blue);

    painter->fillRect(20, 20, 1000, 500, *gradVer);

    delete gradVer;*/

    // Самый простой и правильный способ — создавать градиент на стеке (без new) и передавать его напрямую.
    //Объект класса QLinearGradient создает линейный градиент с областью интерполяции, лежащей между двумя точками,
    //координаты которых передаются объекту в качестве соответствующих параметров:
    QLinearGradient gradVer(0, 25, 0, 300);

    //Цвета в градиенте определяются с помощью точек останова.
    //Метод setColorAt() создает точку останова в заданной позиции с заданным цветом:
    gradVer.setColorAt(0.0, Qt::darkGreen);
    gradVer.setColorAt(0.5, Qt::yellow);
    gradVer.setColorAt(1.0, Qt::darkMagenta);

    //Заполняем прямоугольник градиентом:
    painter->fillRect(20, 20, 300, 280, gradVer);
    painter->drawText(100, 325, "Vertical Gradient");

    //////////////////////////////////////////////////

    QLinearGradient gradHor; // конструтор по умолчанию без параметров

    gradHor.setStart(20, 0); // стартовая позиция градиента
    gradHor.setFinalStop(320, 0); // финальная позиция градиента

    gradHor.setColorAt(0.0, Qt::black);
    gradHor.setColorAt(0.2, Qt::red);
    gradHor.setColorAt(0.5, Qt::darkCyan);
    gradHor.setColorAt(0.7, Qt::yellow);
    gradHor.setColorAt(0.9, Qt::darkBlue);

    //painter->fillRect(20, 340, 300, 280, gradHor);
    // То же самое двумя командами;
    painter->setBrush(gradHor);
    painter->drawRect(20, 340, 300, 280);
    // И подпись:
    painter->drawText(100, 630, "Horizontal Gradient");
}
