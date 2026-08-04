# \<QDesktopWidget\> **был полностью удален** из библиотеки. 

В Qt 5 он считался устаревшим (deprecated), а при переходе на Qt 6 разработчики окончательно убрали его из состава модуля QtWidgets. \[1, 2\]

## **Что использовать вместо него**

Для работы с экранами, их размерами и геометрией теперь нужно использовать класс **QScreen** совместно с **QGuiApplication**. \[1, 2\]

Ниже приведены готовые решения для самых частых задач:

> * **Получить размер главного экрана:**  
>   *// Раньше (Qt5):*  
>   *// QRect screenGeometry \= QApplication::desktop()-\>screenGeometry();*

>   *// Сейчас (Qt6):*  
>   QRect screenGeometry \= QGuiApplication::primaryScreen()-\>geometry();

> * **Центрировать окно на экране:**  
>   *// В конструкторе вашего QWidget:*  
>   QScreen \*screen \= QGuiApplication::primaryScreen();  
>   QRect screenGeometry \= screen-\>geometry();

>   int x \= (screenGeometry.width() \- width()) / 2;  
>   int y \= (screenGeometry.height() \- height()) / 2;  
>   move(x, y);

> * **Получить количество подключенных мониторов:**  
>   int screenCount \= QGuiApplication::screens().size();

> * **Доступ к конкретному монитору по индексу:**  
>   QList\<QScreen \*\> screens \= QGuiApplication::screens();  
>   if (screens.size() \> 1) {  
>       QRect secondScreenGeometry \= screens.at(1)-\>geometry();  
>   }

## **Что нужно изменить в коде**

> 1. Удалите строку \#include \<QDesktopWidget\>.  
> 2. Добавьте подключение новых заголовочных файлов:  
>    \#include \<QGuiApplication\>  
>    \#include \<QScreen\>

> 3. Замените вызовы QApplication::desktop() на методы QGuiApplication::primaryScreen() или QGuiApplication::screens(). \[1, 2\]

---

**Полезные материалы по теме:**

Если вам нужно отслеживать динамическое изменение разрешения экрана или подключение новых мониторов, изучите официальную документацию по классу [QScreen на сайте Qt Documentation](https://doc.qt.io/qt-6/qscreen.html). Для понимания глобальных изменений при переходе со старых версий ознакомьтесь с [руководством по портрованию кода на Qt 6](https://doc.qt.io/qt-6/portingguide.html).

Если ваш код завязан на специфические старые функции QDesktopWidget, расскажите, **какую именно задачу** вы пытаетесь решить (например, развернуть окно на весь экран, определить координаты курсора или работать с мультимониторными системами)? Я помогу переписать этот фрагмент под синтаксис Qt6.

\[1\] [https://forum.qt.io](https://forum.qt.io/topic/141159/what-should-i-use-instead-of-qdesktopwidget-resized-in-qt-6)  
\[2\] [https://stackoverflow.com](https://stackoverflow.com/questions/55227303/qt-qdesktopwidget-is-deprecated-what-should-i-use-instead)
