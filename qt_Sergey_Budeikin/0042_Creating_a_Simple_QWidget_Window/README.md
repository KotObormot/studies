2026-05-29 0042 Создание простейшего окна типа QWidget / 0042 Creating a simple QWidget window

https://www.youtube.com/watch?v=xUK__3ViZN8&list=PL0-ON4z3RPUO-BMP4L-9UvG2ADmMWhW24

1 203 просмотра  23 окт. 2021 г.  Qt Начало
В данном видео уроке мы создадим с вами окно QWidget и добавим в него название, иконку и подсказку.
/ 
1,203 views Oct 23, 2021 Qt Start
In this video tutorial, we'll create a QWidget window and add a title, icon, and tooltip.

===========================================

See also https://ravesli.com/urok-6-osnovy-raboty-s-gui-v-qt5/#toc-0

https://ravesli.com/urok-6-osnovy-raboty-s-gui-v-qt5/#toc-1

https://ravesli.com/urok-6-osnovy-raboty-s-gui-v-qt5/#toc-2

Ну что, друзья, вот мы и добрались до программирования стандартных графических приложений с помощью Qt5. На этом уроке мы попробуем создать наши первые программы, которые будут содержать такие графические элементы, как: кнопка, значок приложения, всплывающая подсказка, различные курсоры мыши, а также рассмотрим, как можно центрировать окно нашей программы и бегло коснемся вопроса работы механизма «сигнал-слот».

А начнем мы с простого примера, который отображает на экранe стандартное окно.

Всплывающая подсказка — это небольшой всплывающий прямоугольник с некоторым текстом, который появляется, когда вы наводите курсор на какой-нибудь элемент в приложении. 

Mы зададим иконку для приложения. Большинство оконных менеджеров отображают этот значок в левом углу заголовка и на панели задач.
Для отображения иконки мы используем метод setWindowIcon() и класс QIcon. Иконка представляет собой небольшой .png-файл, расположенный в текущем рабочем каталоге.

/ 

Well, friends, we've finally reached the point of programming standard graphical applications using Qt5. In this lesson, we'll try creating our first programs that will contain graphical elements such as a button, an application icon, a tooltip, and various mouse cursors. We'll also look at how to center our program window and briefly touch on how the signal-slot mechanism works.

We'll start with a simple example that displays a standard window.

A tooltip is a small pop-up rectangle with some text that appears when you hover over an element in an app.

We'll set an icon for the application. Most window managers display this icon in the left corner of the title bar and on the taskbar. To display the icon, we use the setWindowIcon() method and the QIcon class. The icon is a small .png file located in the current working directory.

============================================

See also https://metanit.com/cpp/qt/1.5.php

============================================
