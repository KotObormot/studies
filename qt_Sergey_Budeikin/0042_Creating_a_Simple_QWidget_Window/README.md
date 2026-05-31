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

#Как узнать свой оконный менеджер?

~$ echo $XDG_CURRENT_DESKTOP

// Если выведет GNOME, то ваш WM — Mutter. Если KDE — то KWin.

ubuntu:GNOME

Как проверить ваш протокол отображения?

~$ echo $XDG_SESSION_TYPE

//Если вывод wayland — setWindowIcon работать в системе не будет. Нужно создавать .desktop файл для приложения. Если вывод x11 — функция отработает штатно, иконка появится.

wayland

У вас активирован современный графический протокол Wayland (в связке с оконным менеджером Mutter).

В этой среде прямой вызов setWindowIcon(QIcon(":/icon/icon/web.png")) из кода Qt не отобразит иконку в панели задач (Dock) или меню переключения Alt+Tab. 

Композитор Wayland полностью игнорирует попытки приложения самостоятельно «нарисовать» себе системную иконку из соображений безопасности и производительности.

Чтобы ваша иконка гарантированно появилась на экране, вам нужно связать окно приложения с системным файлом запуска (ярлыком):

1) Вам необходимо жестко задать имя класса окна (DesktopFileName), чтобы Wayland понял, к какому ярлыку на рабочем столе относится запущенный процесс.

2) Создайте файл ярлыка (.desktop)

Wayland берет иконки только из системных ярлыков. Создайте текстовый файл, который свяжет ваш бинарник и иконку.

3) Дайте файлу права на запуск

Чтобы не создавать .desktop-файл руками на каждом компьютере, добавьте автоматическое создание ярлыка прямо в ваш файл CMakeLists.txt. 
Поскольку вы используете CMake, мы можем сделать так, чтобы при каждом запуске проекта из Qt Creator ярлык .desktop создавался автоматически, а пути к исполняемому файлу и вашей иконке прописывались сами.

Почему в самом заголовке окна нет иконки?

Особенности дизайна GNOME: Разработчики графического окружения GNOME (которое используется в Ubuntu по умолчанию) еще несколько лет назад полностью отказались от иконок в заголовках окон. По их гайдлайнам интерфейса (Human Interface Guidelines), иконка внутри рамки окна считается визуальным мусором, который дублирует информацию и занимает лишнее место.

Ограничения Wayland: Протокол Wayland принципиально не позволяет приложениям рисовать что-либо в области декораций окон (рамках), если это не заложено темой оформления самой операционной системы. Оконный менеджер Mutter намеренно не выводит туда значки программ.

/ 

Well, friends, we've finally reached the point of programming standard graphical applications using Qt5. In this lesson, we'll try creating our first programs that will contain graphical elements such as a button, an application icon, a tooltip, and various mouse cursors. We'll also look at how to center our program window and briefly touch on how the signal-slot mechanism works.

We'll start with a simple example that displays a standard window.

A tooltip is a small pop-up rectangle with some text that appears when you hover over an element in an app.

We'll set an icon for the application. Most window managers display this icon in the left corner of the title bar and on the taskbar. To display the icon, we use the setWindowIcon() method and the QIcon class. The icon is a small .png file located in the current working directory.

How do I find out my window manager?

~$ echo $XDG_CURRENT_DESKTOP

// If it displays GNOME, then your WM is Mutter. If KDE, then KWin.

ubuntu:GNOME

How do I check my display protocol?

~$ echo $XDG_SESSION_TYPE

// If the output is wayland, setWindowIcon won't work in the system. You need to create a .desktop file for the application. If the output is x11, the function will work properly, and the icon will appear.

wayland

You have the modern Wayland graphics protocol enabled (in conjunction with the Mutter window manager).

In this environment, directly calling setWindowIcon(QIcon(":/icon/icon/web.png")) from Qt code will not display the icon in the taskbar (Dock) or the Alt+Tab menu.

The Wayland compositor completely ignores applications' attempts to draw their own system icons for security and performance reasons.

To ensure your icon appears on the screen, you need to associate the application window with a system launch file (shortcut):

1) You need to hardcode the window class name (DesktopFileName) so Wayland knows which desktop shortcut the running process belongs to.

2) Create a shortcut file (.desktop)

Wayland only uses icons from system shortcuts. Create a text file that associates your binary with the icon.

3) Grant the file execution permissions.

To avoid manually creating a .desktop file on each computer, add automatic shortcut creation directly to your CMakeLists.txt file.
Since you're using CMake, we can ensure that a .desktop shortcut is automatically created each time a project is launched from Qt Creator, and the paths to the executable file are automatically specified for both your project and the client.

Why isn't there an icon in the window title bar?

GNOME design features: The developers of the GNOME desktop environment (which is used by default in Ubuntu) completely abandoned icons in window title bars several years ago. According to their Human Interface Guidelines, an icon inside a window frame is considered visual clutter, duplicating information and taking up unnecessary space.

Wayland limitations: The Wayland protocol fundamentally prevents applications from drawing anything in window decorations (frames) unless it's specifically included in the operating system's theme. The Mutter window manager intentionally does not display program icons there.


============================================

See also https://metanit.com/cpp/qt/1.5.php

===========================================
