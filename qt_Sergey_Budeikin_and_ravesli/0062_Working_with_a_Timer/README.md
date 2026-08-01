# 2026-07-05 0062 Работа с таймером / 0062 Working with a timer

https://www.youtube.com/watch?v=em_DBdYtSuc&list=PL0-ON4z3RPUO-BMP4L-9UvG2ADmMWhW24

228 просмотров  5 нояб. 2021 г.  Qt Начало

В данном видео уроке мы с вами рассмотрим один из примеров как можно работать с таймером в Qt. / 228 views November 5, 2021 Qt Start
In this video tutorial, we'll look at one example of how to work with a timer in Qt.

### See also https://ravesli.com/urok-9-sloty-signaly-i-sobytiya-v-qt5/#toc-5

#### Таймер

Таймер используется для реализации одиночного действия или же повторяющихся задач. Хорошим примером, где мы можем задействовать таймер, являются часы; каждую секунду мы должны обновлять нашу метку, отображающую текущее время.

В следующем примере мы попробуем отобразить в окне текущее местное время.

/

#### Timer

A timer is used to implement a single action or recurring tasks. A good example of where we can use a timer is a clock; every second, we need to update our label displaying the current time.

In the next example, we'll try displaying the current local time in a window.

==================================================================

# для чего используется q_unused(event)

Макрос Q_UNUSED(event) во фреймворке Qt используется для того, чтобы подавить предупреждения компилятора (compiler warnings) о неиспользуемой переменной event. [1] 
Обычно этот макрос пишут внутри переопределенных функций обработки событий, когда аргумент функции (например, указатель на событие) фактически не нужен внутри тела метода. [2] 
## Зачем это нужно?

* Чистота сборки: Компиляторы (такие как GCC, Clang или MSVC) при включенных флагах строгого контроля (например, -Wunused-parameter) выдают предупреждения, если аргумент функции объявлен, но не используется. Q_UNUSED убирает этот шум.
* Строгие правила: Во многих проектах включен режим «предупреждения как ошибки» (-Werror). Без этого макроса код просто не скомпилируется.
* Специфика ООП и виртуальных функций: Вы обязаны сохранить сигнатуру базового класса при переопределении метода (например, paintEvent(QPaintEvent *event)), даже если для вашей логики сам объект event не требуется. [2, 3] 

## Как это работает «под капотом»?
Макрос Q_UNUSED(x) раскрывается компилятором в простое приведение переменной к типу void:

#define Q_UNUSED(x) (void)x;

Для компилятора такое выражение означает «переменная была упомянута и задействована», при этом никакого реального исполняемого кода или нагрузки на процессор не создается.
## Пример использования

void MyWidget::mousePressEvent(QMouseEvent *event)

{
    
    // Нам неважно, где именно кликнули (координаты в event)
    // Мы просто реагируем на сам факт клика
    Q_UNUSED(event); 

    emit widgetClicked();
}


## Альтернатива в современном C++
Начиная с C++11 и C++17, вместо макроса Qt можно использовать стандартные языковые средства:

   1. Удаление имени переменной из сигнатуры (C++11):
   
   void MyWidget::mousePressEvent(QMouseEvent *) // Имя переменной просто опущено

    {
       // Код без макроса
    }
   
   2. Атрибут [[maybe_unused]] (C++17):
   
   void MyWidget::mousePressEvent([[maybe_unused]] QMouseEvent *event)
   
    {
       // Компилятор знает, что event может не использоваться
    }
   
   


[1] [https://qt.ucoz.net](https://qt.ucoz.net/blog/makros_q_unused/2009-10-18-29)

[2] [https://ravesli.com](https://ravesli.com/urok-15-sozdayom-igru-arkanoid-v-qt5-s/)

[3] [https://evileg.com](https://evileg.com/ru/post/83/)

--------------------------------------------------------

В стандарте C++20 макрос Q_UNUSED по-прежнему отлично работает для обратной совместимости, но язык предлагает более элегантные встроенные инструменты.
Для чистого кода в C++20 лучше полностью отказаться от макросов Qt в пользу стандартизированных подходов.
## 1. Лучший способ: Атрибут [[maybe_unused]]
Этот атрибут появился в C++17, но в C++20 он стал стандартом де-факто для подавления предупреждений компилятора. Он применяется прямо в сигнатуре функции.

* Где разместить: Перед типом аргумента или перед именем переменной.
* Пример:

void MyWidget::mousePressEvent([[maybe_unused]] QMouseEvent *event)
    
    {
    // Код компилируется без предупреждений (warnings)
    // Макрос Q_UNUSED(event) внутри тела функции больше не нужен
    }

## 2. Классический способ: Безымянный параметр
Если вам вообще не нужен этот объект внутри функции, в C++20 (как и в C++11) можно просто стереть имя переменной, оставив только её тип.

* Пример:

void MyWidget::mousePressEvent(QMouseEvent *) 
    
    {
        // Имя переменной удалено, компилятор спокоен
    }


* Минус способа: Если вам внезапно понадобится event во время отладки, придется возвращать имя переменной обратно в сигнатуру. С [[maybe_unused]] такой проблемы нет — имя всегда под рукой.

## Как включить строгий режим C++20 в Qt-проекте?
Чтобы компилятор сообщал обо всех неиспользуемых переменных (и заставлял вас использовать [[maybe_unused]]), добавьте флаги строгого контроля в файл сборки.
Если вы используете CMake (рекомендуется для Qt 6):

    set(CMAKE_CXX_STANDARD 20)

    set(CMAKE_CXX_STANDARD_REQUIRED ON)
### Включение предупреждений как ошибок для GCC/Clang

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wunused-parameter -Werror)

Если вы используете старый qmake (.pro файл):

CONFIG += c++20

### Включение предупреждений
QMAKE_CXXFLAGS += -Wall -Wextra -Wunused-parameter -Werror


###### ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Комбинация CMake + GCC идеально подходит для настройки строгого режима сборки в C++20. Ограничивать неиспользуемые переменные на уровне компилятора через флаги — лучшая практика, так как это гарантирует чистоту кода на этапе сборки.
Ниже представлен готовый фрагмент для вашего CMakeLists.txt, который принудительно включает стандарт C++20 и активирует жесткий контроль над предупреждениями (warnings) для компилятора GCC. [1] 
## Настройка CMakeLists.txt
Добавьте эти строки в корневой файл CMakeLists.txt (строки установки стандарта должны идти до объявления целей вроде add_executable или add_library): [1, 2] 

cmake_minimum_required(VERSION 3.16)

project(MyQtProject LANGUAGES CXX)
#### 1. Принудительно включаем стандарт C++20
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF) // Использовать чистый C++20 без расширений GNU (опционально)
#### ... здесь идет поиск пакетов Qt (find_package) и создание таргета ...
    add_executable(MyTarget main.cpp mywidget.cpp)
#### 2. Настраиваем строгие флаги GCC конкретно для вашего таргета
    target_compile_options(MyTarget PRIVATE
    
    -Wall                   # Включить базовые предупреждения
   
    -Wextra                 # Включить дополнительные предупреждения (включая неиспользуемые параметры)
    
    -Wunused-parameter      # Явный контроль неиспользуемых аргументов в функциях
    
    -Werror                 # Любое предупреждение прерывает сборку (предупреждение = ошибка)
)

## Как теперь писать код в проекте?
После перезапуска конфигурации CMake, если вы оставите аргумент функции без внимания, GCC прервет сборку с ошибкой error: unused parameter ‘event’.
Чтобы этого не происходило, пишите код в стиле C++20: [3] 
### Вариант А: Использование [[maybe_unused]] (Рекомендуется)
Используйте этот атрибут. Он явно говорит GCC, что переменная event специально оставлена неиспользуемой: [2] 

    void MyWidget::mousePressEvent([[maybe_unused]] QMouseEvent *event)

    {
        // Сборка пройдет успешно. 
        // Макросы Qt (Q_UNUSED) внутри функции больше не нужны.
        emit widgetClicked(); 
    }

### Вариант Б: Удаление имени из сигнатуры
Если тело функции гарантированно никогда не обратится к объекту события, просто сотрите имя event, оставив только тип данных:

    void MyWidget::mousePressEvent(QMouseEvent *)
    {
        // Ошибки не будет, так как для GCC переменная "не существует"
        emit widgetClicked();
    }



[1] [https://cmake.org](https://cmake.org/cmake/help/v3.20/guide/tutorial/index.html?highlight=destination)
[2] [https://www.qtcentre.org](https://www.qtcentre.org/threads/72078-Can-not-use-the-modules-feature-from-c-20-with-Qt-Creator-and-VS)
[3] [https://stackoverflow.com](https://stackoverflow.com/questions/64889383/how-to-enable-stdclatest-in-cmake)
[4] [https://cmake.org](https://cmake.org/cmake/help/latest/manual/cmake-generator-expressions.7.html)
