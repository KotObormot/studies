2026-07-03 0060 Событие перемещения виджета / 0060 Widget move event

https://www.youtube.com/watch?v=2EGx-pfvKZE&list=PL0-ON4z3RPUO-BMP4L-9UvG2ADmMWhW24

156 просмотров  5 нояб. 2021 г.  Qt Начало
В данном видео уроке мы с вами разберём обработчик событий который отвечает за перемещения окна.
/
156 views November 5, 2021 Qt Start
In this video tutorial, we'll look at the event handler responsible for window movement.

See also https://ravesli.com/urok-9-sloty-signaly-i-sobytiya-v-qt5/#toc-3

Класс QMoveEvent

Класс QMoveEvent содержит параметры событий, возникающих при перемещении виджета. В следующем примере мы реагируем на событие перемещения, затем определяем текущие координаты x и y верхнего левого угла клиентской области окна и устанавливаем эти значения в заголовок окна. 

/ 

The QMoveEvent class

The QMoveEvent class contains parameters for events that occur when a widget is moved. In the following example, we respond to a move event, then determine the current x and y coordinates of the upper-left corner of the window's client area and set these values to  the window's title.
