2026-06-28 0054 Вложенные компоновки / 0054 Nested Layouts

 https://www.youtube.com/watch?v=6Rra7L1-zD4&list=PL0-ON4z3RPUO-BMP4L-9UvG2ADmMWhW24&index=54
 
 173 просмотра  31 окт. 2021 г.  Qt Начало
 В данном видео уроке мы с вами разберём что такое вложенные компоновки и как при помощи вложенных компоновок создавать достаточно сложные виджеты.
 /
 173 views Oct 31, 2021 Qt Start
 In this video tutorial, we'll explore nested layouts and how to create complex widgets using them.
 
 See also https://ravesli.com/urok-8-upravlenie-komponovkoj-vidzhetov-v-qt5/#toc-4
 
 Идея следующего примера состоит в том, чтобы показать, что менеджеры компоновки могут быть вложены друг в друга. Комбинируя даже простые способы размещения элементов на форме, мы       можем создавать сложные формы и окна. Для того, чтобы вложить одну компоновку в другую, используется метод addLayout().
 
 В следующем примере мы создадим окно, состоящее из 4 кнопок и 1 виджета QListWidget. Кнопки сгруппированы в вертикальный столбец и расположены справа от виджета-списка. Если мы изменим размер окна, размеры QListWidget также изменятся.
 
 /
 
 The idea behind the following example is to demonstrate that layout managers can be nested. By combining even simple ways of placing elements on a form, we can create complex forms and windows. To nest one layout within another, use the addLayout() method.
 
 In the following example, we'll create a window consisting of four buttons and one QListWidget. The buttons are grouped in a vertical column and positioned to the right of the list widget. If we resize the window, the QListWidget's dimensions will also change.

