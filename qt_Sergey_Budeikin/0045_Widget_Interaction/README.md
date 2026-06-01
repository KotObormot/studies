2026-06-01 0045 Взаимодействие виджетов / 0045 Widget Interaction

https://www.youtube.com/watch?v=RkbfZBB-ypQ&list=PL0-ON4z3RPUO-BMP4L-9UvG2ADmMWhW24

329 просмотров  24 окт. 2021 г.  Qt Начало
В данном примере мы посмотрим на практике как взаимодействуют виджеты между собой при помощи сигналов и слотов,  так же научимся создавать свои собственные слоты. 
/ 
329 views Oct 24, 2021 Qt Start
In this example, we'll see in practice how widgets interact with each other using signals and slots, and we'll also learn how to create our own slots.

==========================================================================

See also https://ravesli.com/urok-6-osnovy-raboty-s-gui-v-qt5/#toc-5

Мы заканчиваем этот урок примером, который демонстрирует возможность виджетов взаимодействовать друг с другом. Код данного примера разделен на три файла.

Следующий код является заголовочным файлом, в котором мы определяем два слота и виджет lbl.

Заголовочный файл — plusminus.h

У нас есть две кнопки и виджет lbl. С помощью кнопок мы увеличиваем или уменьшаем число, отображаемое в lbl.

Файл реализации — plusminus.cpp

В методе OnPlus() мы определяем текущее значение в lbl. Виджет lbl отображает строковое значение, поэтому сначала его нужно преобразовать в целое число. Затем мы это число увеличиваем, конвертируем получившееся число снова в строковое значение и устанавливаем новый текст для label

Метод OnMinus() отличается от метода OnPlus() только тем, что в OnMinus() значение не инкрементируется, а декрементируется (уменьшается на единицу).

Hаш основной файл — main.cpp.

/ 

We conclude this lesson with an example that demonstrates how widgets can interact with each other. The code for this example is divided into three files.

The following code is a header file in which we define two slots and the lbl widget.

Header file — plusminus.h

We have two buttons and an lbl widget. Using the buttons, we increment or decrement the number displayed in lbl.

Implementation file — plusminus.cpp

In the OnPlus() method, we determine the current value in lbl. The lbl widget displays a string value, so we first convert it to an integer. We then increment this number, convert the resulting number back to a string, and set the new text for the label.

The OnMinus() method differs from the OnPlus() method only in that in OnMinus(), the value is decremented (decreased by one) rather than incremented.

Our main file — main.cpp
