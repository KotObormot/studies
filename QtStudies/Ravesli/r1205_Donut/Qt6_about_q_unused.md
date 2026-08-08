# для чего используется q\_unused(event)

- [AI](https://www.google.com/search?udm=50\&mstk=AUtExfAZNwVuAoIPKPk36LDoK1DCQDSf0qJCo6H-8XB3o6p\_jpXBGjRrdiYS7KyfjECcppjV1hKMs8X3Lq0zsbSvEHb4mDBZyav87hMIVVyBdYOW9nNmIipELYOMPfqL\_rhyGDBa8ZZjuE\_H389QSqPS6Y2aTz7Da7xonuTHXbXQgOEDZMz7xGrfgBHBmULkwXyPUL6v-50bnxPiH3XVJmzTsvdsyOQK6ID5lodqY5vSNmlf1vqfJZub8udxtAPnbdvlZV9GIXFrdICXfQ\&csuir=1\&q=%D0%B4%D0%BB%D1%8F+%D1%87%D0%B5%D0%B3%D0%BE+%D0%B8%D1%81%D0%BF%D0%BE%D0%BB%D1%8C%D0%B7%D1%83%D0%B5%D1%82%D1%81%D1%8F+q\_unused%28event%29\&aep=146\&atvm=2\&mtid=6KhKauP6BY6O1fIPppXXwQ0)

Макрос Q\_UNUSED(event) во фреймворке Qt используется для того, чтобы **подавить предупреждения компилятора (compiler warnings) о неиспользуемой переменной** event. \[1\]

Обычно этот макрос пишут внутри переопределенных функций обработки событий, когда аргумент функции (например, указатель на событие) фактически не нужен внутри тела метода. \[2\]

## **Зачем это нужно?**

> * **Чистота сборки:** Компиляторы (такие как GCC, Clang или MSVC) при включенных флагах строгого контроля (например, \-Wunused-parameter) выдают предупреждения, если аргумент функции объявлен, но не используется. Q\_UNUSED убирает этот шум.  
> * **Строгие правила:** Во многих проектах включен режим «предупреждения как ошибки» (-Werror). Без этого макроса код просто не скомпилируется.  
> * **Специфика ООП и виртуальных функций:** Вы обязаны сохранить сигнатуру базового класса при переопределении метода (например, paintEvent(QPaintEvent \*event)), даже если для вашей логики сам объект event не требуется. \[2, 3\]

## **Как это работает «под капотом»?**

Макрос Q\_UNUSED(x) раскрывается компилятором в простое приведение переменной к типу void:

`#define Q_UNUSED(x) (void)x;`

Для компилятора такое выражение означает «переменная была упомянута и задействована», при этом никакого реального исполняемого кода или нагрузки на процессор не создается.

## **Пример использования**

    void MyWidget::mousePressEvent(QMouseEvent *event) {  
        // Нам неважно, где именно кликнули (координаты в event)  
        // Мы просто реагируем на сам факт клика  
        Q_UNUSED(event); 
    
        emit widgetClicked();  
    }

## **Альтернатива в современном C++**

Начиная с C++11 и C++17, вместо макроса Qt можно использовать стандартные языковые средства:

  **1.Удаление имени переменной из сигнатуры (C++11):**  
  
        void MyWidget::mousePressEvent(QMouseEvent *) { // Имя переменной просто опущено  
            // Код без макроса
        }

 **2.Атрибут \[\[maybe\_unused\]\] (C++17):**  
>    `void MyWidget::mousePressEvent([[maybe_unused]] QMouseEvent *event)`  
>    `{`  
>        `// Компилятор знает, что event может не использоваться`  
>    `}`

Если вы хотите оптимизировать свой код или узнать, как настроить предупреждения в файле проекта Qt (.pro / CMakeLists.txt), **напишите, какую версию стандарта C++** вы используете.

\[1\] [https://qt.ucoz.net](https://qt.ucoz.net/blog/makros_q_unused/2009-10-18-29)  
\[2\] [https://ravesli.com](https://ravesli.com/urok-15-sozdayom-igru-arkanoid-v-qt5-s/)  
\[3\] [https://evileg.com](https://evileg.com/ru/post/83/)

Комбинация **CMake \+ GCC** идеально подходит для настройки строгого режима сборки в C++20. Ограничивать неиспользуемые переменные на уровне компилятора через флаги — лучшая практика, так как это гарантирует чистоту кода на этапе сборки.

Ниже представлен готовый фрагмент для вашего `CMakeLists.txt`, который принудительно включает стандарт C++20 и активирует жесткий контроль над предупреждениями (warnings) для компилятора GCC. \[1\]

## Настройка CMakeLists.txt

Добавьте эти строки в корневой файл `CMakeLists.txt` (строки установки стандарта должны идти **до** объявления целей вроде `add_executable` или `add_library`): \[1, 2\]

    cmake_minimum_required(VERSION 3.16)
    
    project(MyQtProject LANGUAGES CXX)
    
    # 1. Принудительно включаем стандарт C++20*
    
    set(CMAKE_CXX_STANDARD 20)
    
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    
    set(CMAKE_CXX_EXTENSIONS OFF) # Использовать чистый C++20 без расширений GNU (опционально)
    
    # ... здесь идет поиск пакетов Qt (find\_package) и создание таргета ...
    
    add_executable(MyTarget main.cpp mywidget.cpp)

    # 2. Настраиваем строгие флаги GCC конкретно для вашего таргета
    
    target_compile_options(MyTarget PRIVATE
    
        -Wall                   # Включить базовые предупреждения
    
        -Wextra                 # Включить дополнительные предупреждения (включая неиспользуемые параметры)
    
        -Wunused-parameter      # Явный контроль неиспользуемых аргументов в функциях
    
        -Werror                 # Любое предупреждение прерывает сборку (предупреждение = ошибка)
    
    )

## Как теперь писать код в проекте?

После перезапуска конфигурации CMake, если вы оставите аргумент функции без внимания, GCC прервет сборку с ошибкой `error: unused parameter ‘event’`.

Чтобы этого не происходило, пишите код в стиле C++20: \[3\]

## **Вариант А: Использование `[[maybe_unused]]` (Рекомендуется)**

Используйте этот атрибут. Он явно говорит GCC, что переменная `event` специально оставлена неиспользуемой: \[2\]

`void MyWidget::mousePressEvent(\[\[maybe\_unused\]\] QMouseEvent \*event)`

`{`

    *// Сборка пройдет успешно.* 

    *// Макросы Qt (Q\_UNUSED) внутри функции больше не нужны.*

    emit widgetClicked(); 

`}`

## **Вариант Б: Удаление имени из сигнатуры**

Если тело функции гарантированно никогда не обратится к объекту события, просто сотрите имя `event`, оставив только тип данных:

`void MyWidget::mousePressEvent(QMouseEvent *)`

`{`

    // Ошибки не будет, так как для GCC переменная "не существует"

    emit widgetClicked();

`}`

Если вы хотите сделать эти флаги компилятора общими для всех создаваемых библиотек и исполняемых файлов в проекте, я могу показать, как настроить глобальный шаблон через `add_compile_options`. Написать такой пример? \[4\]

\[1\] [https://cmake.org](https://cmake.org/cmake/help/v3.20/guide/tutorial/index.html?highlight=destination)

\[2\] [https://www.qtcentre.org](https://www.qtcentre.org/threads/72078-Can-not-use-the-modules-feature-from-c-20-with-Qt-Creator-and-VS)

\[3\] [https://stackoverflow.com](https://stackoverflow.com/questions/64889383/how-to-enable-stdclatest-in-cmake)

\[4\] [https://cmake.org](https://cmake.org/cmake/help/latest/manual/cmake-generator-expressions.7.html)



#  ẞ
