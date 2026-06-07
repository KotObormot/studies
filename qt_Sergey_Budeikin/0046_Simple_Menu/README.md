2026-06-04...2026-05-07 0046 Создание простейшего меню / 0046 Creating a simple menu 

https://www.youtube.com/watch?v=SbNvb82tdsQ&list=PL0-ON4z3RPUO-BMP4L-9UvG2ADmMWhW24

318 просмотров  24 окт. 2021 г.  Qt Начало
В данном видео уроке мы с вами создадим простейшее меню которое будет наполнено одним действием.
/ 
318 views Oct 24, 2021 Qt Start
In this video tutorial, we'll create a simple menu filled with a single action.

================================================================

See also https://ravesli.com/urok-7-sozdanie-menyu-i-paneli-instrumentov-v-qt5/#toc-0

На этом уроке мы поговорим о создании таких графических элементов приложения, как меню и панель инструментов. Большинство современных приложений имеют как меню, так и панель инструментов, которые содержат более-менее идентичный набор команд.

Меню является стандартной частью приложения с графическим интерфейсом и предоставляет пользователю возможность заняться «исследованием» приложения (изучать доступные команды), в то время как панели инструментов обеспечивают быстрый доступ к наиболее часто используемым командам.

Заголовочный файл — simplemenu.h: У нас есть строка меню с элементами и действиями, которые активируются по нажатию кнопки мыши (на соответствующий пункт). Чтобы работать с меню, нам сначала нужно выполнить наследование виджета QMainWindow. 

Файл реализации — simplemenu.cpp: Класс QAction представляет собой абстрактное действие пользовательского интерфейса, которое может быть вставлено в виджеты. В приложениях множество общих команд может быть вызвано через меню, панель инструментов и сочетания горячих клавиш. Поскольку пользователь ожидает, что каждая команда будет выполняться одним и тем же способом, независимо от используемого пользовательского интерфейса, то полезно представить каждую команду как действие. При этом каждый объект класса QMenu может иметь один или несколько объектов действия.

Основной файл программы — main.cpp.

/ 

In this lesson, we'll discuss creating graphical application elements such as menus and toolbars. Most modern applications have both menus and toolbars, which contain a more or less identical set of commands.

Menus are a standard part of a GUI application and allow the user to explore the application (learn the available commands), while toolbars provide quick access to the most frequently used commands.

Header file — simplemenu.h: We have a menu bar with items and actions that are activated by clicking the corresponding item. To work with the menu, we first need to extend the QMainWindow widget.

Implementation file — simplemenu.cpp: The QAction class represents an abstract user interface action that can be embedded in widgets. In applications, many common commands can be accessed through menus, toolbars, and keyboard shortcuts. Since the user expects each command to be executed in the same way, regardless of the user interface used, it is useful to represent each command as an action. Each QMenu class object can have one or more action objects.

The main program file is main.cpp. 
