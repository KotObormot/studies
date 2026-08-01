2026-05-31 0043 Курсор / 0043 Cursor

312 просмотров  23 окт. 2021 г.  Qt Начало
В данном видео уроке мы с вами рассмотрим такую тему как изменяющийся курсор при наведении мышки на различные виджеты.
/ 
312 views Oct 23, 2021 Qt Start
In this video tutorial, we'll explore the topic of changing the cursor when hovering over various widgets.

https://www.youtube.com/watch?v=drI-KrLZ6Ls&list=PL0-ON4z3RPUO-BMP4L-9UvG2ADmMWhW24&index=43

===========================================================

See also https://ravesli.com/urok-6-osnovy-raboty-s-gui-v-qt5/#toc-3

Курсор — это небольшой значок, отображающий на экране положение указателя мыши. В наших программах мы можем использовать различные виды курсоров. В следующем примере мы задействуем три фрейма, каждый из которых будет иметь свой курсор
/ 
A cursor is a small icon that displays the position of the mouse pointer on the screen. We can use different types of cursors in our programs. In the following example, we'll use three frames, each with its own cursor.

===========================================================

See also https://doc.qt.io/qt-6/qcursor.html

В среде Qt Creator (на платформе Ubuntu и других ОС) внешний вид курсора мыши определяется перечислением Qt::CursorShape. Эти стандартные типы задаются на этапе разработки в коде C++ или QML для создания нужного пользовательского интерфейса.

В рамках фреймворка Qt существует множество встроенных типов курсоров. Основные и самые популярные из них сгруппированы ниже:

🛠 Базовые и интерактивные курсоры

 Qt::ArrowCursor: стандартный курсор (стрелка) по умолчанию.

 Qt::PointingHandCursor: рука с указательным пальцем. Показывает, что на элемент можно нажать (аналог курсора pointer в веб-разработке).

 Qt::ForbiddenCursor: перечеркнутый круг. Указывает на то, что действие запрещено.

 Qt::WhatsThisCursor: стрелка со знаком вопроса. Используется для вызова контекстной справки ("Что это такое?").

↔ Курсоры изменения размера

 Qt::SizeHorCursor: двусторонняя горизонтальная стрелка (изменение ширины).

 Qt::SizeVerCursor: двусторонняя вертикальная стрелка (изменение высоты).

 Qt::SizeAllCursor: перекрещенные стрелки для изменения размера окна или объекта во всех направлениях.

 Qt::SizeBDiagCursor и Qt::SizeFDiagCursor: диагональные стрелки изменения размера (для углов).

✍ Текст и операции перетаскивания (Drag & Drop)

 Qt::IBeamCursor: вертикальная черта. Применяется для выделения и ввода текста.
 
 Qt::OpenHandCursor / Qt::ClosedHandCursor: открытая или сжатая ладонь. 
Идеально подходят для захвата и перемещения содержимого (например, карт или изображений).

Qt::DragMoveCursor, Qt::DragCopyCursor, Qt::DragLinkCursor: различные вариации для индикации процесса перетаскивания объектов.

⏳ Состояние системы

Qt::WaitCursor: песочные часы или вращающееся колесико, сигнализирующее о занятости программы.

Qt::BusyCursor: фоновый курсор, который показывает занятость приложения, но при этом позволяет продолжать работу с мышью.


Как применять курсоры?

В коде C++ (на примере виджета):
Для привязки курсора к определенному элементу используется метод setCursor():

cpp   myWidget->setCursor(Qt::PointingHandCursor); // при наведении курсор станет "рукой"

В коде QML (на примере MouseArea):
В QML курсор задается с помощью свойства cursorShape:

qml   MouseArea {
         anchors.fill: parent
         cursorShape: Qt.PointingHandCursor // выбор типа курсора
      }


 для Linux/Ubuntu: В X11/Wayland среда отрисовывает курсоры через библиотеку Xcursor. Поэтому внешний вид конкретного курсора (например, WaitCursor или ArrowCursor) может слегка меняться в зависимости от того, какая системная тема оформления установлена в вашей Ubuntu. 

/ 

In Qt Creator (on Ubuntu and other OSes), the mouse cursor's appearance is defined by the Qt::CursorShape enumeration. These standard types are defined at development time in C++ or QML code to create the desired user interface. 

The Qt framework offers many built-in cursor types. The main and most popular ones are grouped below: 

🛠 Basic and Interactive Cursors 

 Qt::ArrowCursor: The standard default cursor (arrow). 

 Qt::PointingHandCursor: A hand with a pointing finger. Indicates that the element can be clicked (analogous to the pointer cursor in web development).

 Qt::ForbiddenCursor: A circle with a line through it. Indicates that the action is prohibited.

 Qt::WhatsThisCursor: An arrow with a question mark. Used to call context-sensitive help ("What is this?").

↔ Resizing cursors

  Qt::SizeHorCursor: Double-sided horizontal arrow (change width).

  Qt::SizeVerCursor: Double-sided vertical arrow (change height). 

  Qt::SizeAllCursor: Crossed arrows for resizing a window or object in all directions.

  Qt::SizeBDiagCursor and Qt::SizeFDiagCursor: Diagonal resizing arrows (for corners).

✍ Text and Drag & Drop
  
  Qt::IBeamCursor: Vertical bar. Used for selecting and entering text.

  Qt::OpenHandCursor / Qt::ClosedHandCursor: Open or closed hand. Ideal for grabbing and moving content (such as maps or images).
 
  Qt::DragMoveCursor, Qt::DragCopyCursor, Qt::DragLinkCursor: various variations for indicating the progress of dragging objects.

⏳ System Status

  Qt::WaitCursor: an hourglass or a spinning wheel indicating that the program is busy.

  Qt::BusyCursor: a background cursor that indicates that the application is busy, but still allows you to continue working with the mouse.


How to use cursors?

 In C++ code (using a widget as an example):

To bind the cursor to a specific element, use the setCursor() method:

cpp      myWidget->setCursor(Qt::PointingHandCursor); // the cursor will become a "hand" when hovered

In QML code (using MouseArea as an example):
  
  In QML, the cursor is set using the cursorShape property:

qml       MouseArea {
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor // select the cursor type
          }

Note for Linux/Ubuntu: In X11/Wayland, the environment draws cursors through the Xcursor library. Therefore, the appearance of a specific cursor (e.g., WaitCursor or ArrowCursor) may vary slightly depending on the system theme installed in your Ubuntu.
