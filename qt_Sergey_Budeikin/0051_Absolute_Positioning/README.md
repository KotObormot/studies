2026-06-25 0051 Абсолютное позиционирование / 0051 Absolute positioning

https://www.youtube.com/watch?v=RdC1VjEfImI&list=PL0-ON4z3RPUO-BMP4L-9UvG2ADmMWhW24

177 views Oct 26, 2021 Qt Start
In this video tutorial, we'll cover the topic of absolute widget positioning.

See also https://ravesli.com/urok-8-upravlenie-komponovkoj-vidzhetov-v-qt5/#toc-1

Системы компоновки в Qt5

Системы компоновки в Qt5 предоставляют разработчику простой и вместе с тем мощный способ максимально эффективного использования доступного пространства при помощи автоматического размещения виджетов с применением менеджеров компоновки. В статье будут рассмотрены следующие классы менеджеров компоновки:

   QHBoxLayout;

   QVBoxLayout;

   QFormLayout;

   QGridLayout.

На предыдущих уроках мы узнали, что типичное Qt-приложение состоит из различных виджетов, позиционированием которых занимается программист, пишущий программу. Библиотека Qt поддерживает два способа размещения элементов управления на форме приложения:

   абсолютное позиционирование;

   позиционирование с помощью менеджеров компоновки.

Абсолютное позиционирование

При абсолютном позиционировании программист указывает в пикселях положение и размер каждого виджета. При использовании этого способа размещения виджетов следует знать, что:

   размер и положение виджета не изменяются при изменении размера окна;

   приложения выглядят по-разному (часто плохо) на разных платформах;

   изменение шрифтов в приложении может испортить компоновку;

   если мы решим изменить расположение элементов на форме, то должны будем полностью переделать всю компоновку, что, в свою очередь, является довольно утомительным и трудоемким процессом.

Несомненно, есть примеры, в которых нам никто не запрещает использовать способ абсолютного позиционирования элементов. Но в большинстве реальных проектов программисты стараются вместо этого использовать менеджеры компоновки.

Перейдем к рассмотрению примера, в котором задействован метод setGeometry() для размещения виджета в окне с использованием абсолютных координат.

Здесь мы создаем виджет QTextEdit и вручную размещаем его. Метод setGeometry() выполняет две функции: позиционирует виджет в абсолютных координатах и изменяет его размер.


P.s. QDesktopWidget был полностью удален из библиотеки. В Qt 5 он считался устаревшим (deprecated), а при переходе на Qt 6 разработчики окончательно убрали его из состава модуля QtWidgets. Для работы с экранами, их размерами и геометрией теперь нужно использовать класс QScreen совместно с QGuiApplication.


/ 

Layout Systems in Qt5

Layout systems in Qt5 provide developers with a simple yet powerful way to maximize available space by automatically placing widgets using layout managers. This article will cover the following layout manager classes:

QHBoxLayout;

QVBoxLayout;

QFormLayout;

QGridLayout.

In previous lessons, we learned that a typical Qt application consists of various widgets, the positioning of which is handled by the programmer. The Qt library supports two methods for placing controls on an application form:

absolute positioning;

positioning using layout managers.

Absolute Positioning

With absolute positioning, the programmer specifies the position and size of each widget in pixels. When using this method of placing widgets, be aware that:

the widget's size and position do not change when the window is resized;

applications appear differently (often poorly) on different platforms;

Changing fonts in an application can ruin the layout;

If we decide to change the arrangement of elements on a form, we'll have to completely redo the entire layout, which, in turn, is a rather tedious and time-consuming process.

Of course, there are examples where we can use absolute positioning of elements. However, in most real-world projects, programmers tend to use layout managers instead.

Let's look at an example that uses the setGeometry() method to place a widget in a window using absolute coordinates.

Here, we create a QTextEdit widget and manually place it. The setGeometry() method performs two functions: it positions the widget using absolute coordinates and resizes it.

P.s. QDesktopWidget has been completely removed from the library. In Qt 5, it was deprecated, and with the transition to Qt 6, the developers finally removed it from the QtWidgets module. To work with screens, their sizes, and geometry, you now need to use the QScreen class in conjunction with QGuiApplication.

