# 2026-09-06 / Эффект исчезновения / Disappearing effect

- [Ravesli](https://ravesli.com/urok-12-risovanie-v-qt5/#toc-8)

А сейчас мы попробуем создать эффект исчезновения текста. Пример показывает растущий центрированный текст, который с определенного момента начинает постепенно исчезать.

В заголовочном файле определены два обработчика событий:

- обработчик событий отрисовки `paintEvent()`;

- обработчик таймера `timerEvent()`.

//

Now we will try to create a disappearing text effect. The example shows growing centered text that starts to fade out after a certain point.

The header file defines two event handlers:

- drawing event handler `paintEvent()`;

- timer handler `timerEvent()`.

---

- See also [Zetcode](http://zetcode.com/gui/qt5/)

---

- See also [Сергей Будейкин.  / Working with gradients in Qt Creator](https://www.youtube.com/watch?v=3zb6Nf5Nsks&list=PL0-ON4z3RPUMrT8Qv5I7NZixRk_zuqilt&index=58)

1 675 просмотров  31 авг. 2018 г.  QT creator
В данном видео уроке рассказывается достаточно подробно как работать с градиентом в Qt Creator, так же рассмотрены 3 различных возможных градиента в Qt Creator. 
/
1,675 views Aug 31, 2018 QT Creator
This video tutorial explains in detail how to work with gradients in Qt Creator, and also discusses three different possible gradients in Qt Creator.


Градиенты в Qt / Gradients in Qt:

+ QLinearGradient
+ QRadialGradient
+ QConicalGradient

--- 

## Заключение

Начав с основ рисования таких примитивов, как линии и простые фигуры, мы плавно перешли к созданию геометрических фигур с более сложной формой (многоугольники, фигуры с закругленными углами), к рисованию по заданной траектории, рассмотрели построение градиентов и даже нарисовали свой собственный пончик.

На следующем уроке мы научимся создавать свой собственный виджет.


# ẞ
