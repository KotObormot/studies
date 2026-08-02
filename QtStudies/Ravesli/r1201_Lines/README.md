# 2026-08-02 / QPainter/Lines

#### https://ravesli.com/urok-12-risovanie-v-qt5/#toc-0

Сегодня мы немного поупражняемся в рисовании. Для этого в Qt5 есть очень мощный класс QPainter. Он может рисовать всё: от простых линий до сложных геометрических фигур, таких как секторы, дуги окружностей, многоугольники и т.д.

Методика отрисовки объектов средствами Qt5 сводится к следующему:

-   сначала нужно при помощи публичного наследования создать дочерний класс от класса QWidget;

-   в созданном классе переопределить метод перерисовки paintEvent(QPaintEvent *).

Метод paintEvent(QPaintEvent *) всегда вызывается при создании виджета, а также всякий раз, когда нужно перерисовать его внешний вид (например, мы растянули/сжали окно и вместе с этим изменили размеры нашего виджета).

А начнем мы с простого примера, в котором нарисуем в клиентской области окна шесть линий, которые будут отличаться друг от друга стилем.

Для этого мы создадим дочерний класс Lines, наследуя класс QWidget, и поместим код отрисовки линий внутри переопределенного метода paintEvent().

//

Today, we'll practice some drawing. Qt5 provides the well-known QPainter class for this purpose. It can draw everything from simple lines to complex geometric shapes such as sectors, circular arcs, polygons, and so on.

The method for drawing objects with Qt5 is as follows:

-  First, create a subclass of the QWidget class using public inheritance;

- In the created class, override the PaintEvent(QPaintEvent *) repaint method.

The PaintEvent(QPaintEvent *) method is always called when a widget is created, as well as whenever its appearance needs to be repainted (for example, if we resized the window and thereby changed the size of our widget).

We'll start with a simple example in which we'll draw six lines in the client area, each with a different style.

To do this, we create a child class Lines by inheriting the QWidget class, and place the line drawing code inside the overridden PaintEvent() method.

---

#### See also http://zetcode.com/gui/qt5/

# ẞ
