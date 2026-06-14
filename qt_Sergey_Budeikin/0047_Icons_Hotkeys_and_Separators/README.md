2026-06-14  0047 Иконки, горячие клавиши и разделители / 0047 Icons, Hotkeys, and Separators

https://www.youtube.com/watch?v=RnJRF4spFQ0&list=PL0-ON4z3RPUO-BMP4L-9UvG2ADmMWhW24&index=47

235 просмотров  25 окт. 2021 г.  Qt Начало
В данном видео уроке мы с вами создадим меню File в которое добавим три действия к действиям мы добавим иконки и горячие клавиши.
/ 
235 views Oct 25, 2021 Qt Start
In this video tutorial, we'll create a File menu to which we'll add three actions. We'll also add icons and hotkeys to the actions.

See also https://ravesli.com/urok-7-sozdanie-menyu-i-paneli-instrumentov-v-qt5/#toc-1

Теперь давайте немного улучшим наше предыдущее приложение. Добавим в него иконки к пунктам меню, зададим сочетания горячих клавиш и установим разделитель.

Заголовочный файл — anothermenu.h

В данном примере у нас есть одно меню с тремя действиями. При этом только действие Quit является рабочим. Мы также установим разделитель — горизонтальную линию, которая позволит нам группировать действия меню в некоторые логические группы, и сочетание клавиш CTRL+Q, которое будет завершать работу нашего приложения.

Файл реализации — anothermenu.cpp

Основной файл программы — main.cpp

/ 

Now let's improve our previous application a bit. We'll add icons to the menu items, define hotkey combinations, and set a separator.

Header file — anothermenu.h

In this example, we have a single menu with three actions. Only the Quit action is active. We'll also set a separator—a horizontal line—to allow us to group menu actions into logical groups, and a keyboard shortcut, CTRL+Q, to terminate our application.

Implementation file — anothermenu.cpp

The main program file — main.cpp
