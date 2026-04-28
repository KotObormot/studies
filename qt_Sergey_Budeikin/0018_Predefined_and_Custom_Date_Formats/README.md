2026-04-28 0018 Предопределенные и пользоватальские форматы дат / 
0018 Predefined and custom date formats

https://www.youtube.com/watch?v=9d7Cz0zX4Sc&list=PL0-ON4z3RPUO-BMP4L-9UvG2ADmMWhW24&index=18&t=2s

218 просмотров  15 окт. 2021 г.  Qt Начало
В данном видео уроке мы разберём различные форматы отображение даты.
/ 
218 views Oct 15, 2021 Qt Start
In this video tutorial, we'll explore various date display formats.

В контексте разработки на фреймворке Qt, qt::systemlocalshortdate чаще всего относится к формату отображения даты, который соответствует системным настройкам локали пользователя в кратком виде (например, 15.04.2024 вместо 15 апреля 2024 г.).
Основные сведения
В современном API Qt (версии 5 и 6) прямой константы с таким точным именем в нижнем регистре не существует, но она является логической комбинацией двух понятий:

    Локаль (Locale): Использование QLocale::system() для получения настроек региона пользователя.
    Формат (Format): Использование перечисления QLocale::ShortFormat для краткого представления даты. 

Применение в коде (C++)
Чтобы получить дату в системном кратком формате, обычно используется следующий подход:
cpp

#include <QLocale>
#include <QDate>
#include <QString>

// Получаем системную локаль
QLocale systemLocale = QLocale::system();

// Преобразуем текущую дату в строку краткого формата
QString shortDate = systemLocale.toString(QDate::currentDate(), QLocale::ShortFormat);

Используйте код с осторожностью.
Применение в QML
В среде QML для аналогичных целей используются методы объекта Date или Locale: 

    Date.toLocaleDateString(): Автоматически использует системную локаль и по умолчанию может возвращать краткий или длинный формат в зависимости от параметров.
    Пример: new Date().toLocaleDateString(Qt.locale(), Locale.ShortFormat). 

Где это встречается

    QDateTimeEdit: Виджеты ввода даты часто настраиваются на использование системного формата через setDisplayFormat.
    Локализация: Это стандартный способ сделать интерфейс "родным" для пользователя, не заставляя его привыкать к американскому (MM/DD/YYYY) или европейскому (DD.MM.YYYY) формату вручную.

Чтобы задать конкретную маску (формат) для даты в Qt, вы можете использовать специальные символы-заполнители. Вот как это сделать в разных частях фреймворка:
1. В C++ (через QDate или QDateTime)
Метод toString принимает строку формата.
cpp

#include <QDate>
#include <QDebug>

QDate date = QDate::currentDate();

// Примеры популярных масок:
QString s1 = date.toString("dd.MM.yyyy"); // 15.04.2024
QString s2 = date.toString("d MMMM yy");  // 15 апреля 24
QString s3 = date.toString("yyyy-MM-dd"); // 2024-04-15 (ISO)

qDebug() << s1;

Используйте код с осторожностью.
2. В виджетах (QDateTimeEdit)
Если вам нужно, чтобы пользователь вводил дату по определенному шаблону, используйте setDisplayFormat.
cpp

QDateTimeEdit *dateEdit = new QDateTimeEdit(QDate::currentDate());
dateEdit->setDisplayFormat("dd/MM/yy"); // Маска для ввода

Используйте код с осторожностью.
3. В QML
В QML используется метод Qt.formatDate.
qml

Text {
    text: Qt.formatDate(new Date(), "dd.MM.yyyy")
}

Используйте код с осторожностью.
Основные символы маски:

    d: день (1-31)
    dd: день с нулем (01-31)
    M: номер месяца (1-12)
    MM: номер месяца с нулем (01-12)
    MMM: сокращенное название (янв., апр.)
    MMMM: полное название (апреля)
    yy: год две цифры (24)
    yyyy: год четыре цифры (2024)

Важный нюанс: Если вы используете названия месяцев (MMMM), Qt автоматически склоняет их в зависимости от выбранной локали (QLocale).


в Qt 6 (как и в Qt 5.15+) константы Qt::SystemLocalShortDate не существует.
Она была окончательно удалена. Вместо использования перечислений типа Qt::DateFormat, которые раньше пытались охватить всё сразу, в Qt 6 разделены понятия «формат» и «локаль».
Как делать правильно в Qt 6
Вместо старого подхода теперь нужно использовать класс QLocale. Он отвечает за то, как даты выглядят в конкретном регионе.
C++:
cpp

// Вместо Qt::SystemLocalShortDate
QString date = QLocale::system().toString(QDate::currentDate(), QLocale::ShortFormat);

Используйте код с осторожностью.
QML:
qml

// Вместо Qt.SystemLocalShortDate
let dateString = new Date().toLocaleDateString(Qt.locale(), Locale.ShortFormat)

Используйте код с осторожностью.
Почему так сделали?
Раньше флаги вроде Qt::SystemLocalShortDate были «жестко» прописаны в общих типах данных. Теперь логика такая:

    Вы берете объект локали (QLocale::system() для системной или QLocale("en_US") для конкретной).
    Вызываете у неё метод toString().
    Передаете туда степень подробности: QLocale::ShortFormat (кратко) или QLocale::LongFormat (полно).
