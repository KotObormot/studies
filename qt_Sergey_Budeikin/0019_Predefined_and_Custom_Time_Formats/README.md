2026-05-01 0019 Предопределённые и пользовательские форматы времени / 0019 Predefined and custom time formats

https://www.youtube.com/watch?v=xKhnfir7Tos&list=PL0-ON4z3RPUO-BMP4L-9UvG2ADmMWhW24&index=19

195 просмотров  16 окт. 2021 г.  Qt Начало
В данном видео уроке мы поработаем с различными способами отображения текущего времени в консоли. Данные способы работают не только в консоли но и с графическим интерфейсом.
/ 
195 views Oct 16, 2021 Qt Start
In this video tutorial, we'll work with various ways to display the current time in the console. These methods work not only in the console but also with the graphical interface.

как хранить время в UTC

В Qt6 хранение времени в UTC является «золотым стандартом»: это исключает ошибки при переходе на летнее/зимнее время и упрощает синхронизацию между клиентом и сервером.
Вот основные способы реализации:

1. Получение текущего времени в UTCЧтобы получить объект QDateTime, который уже настроен на работу с UTC:

#include <QDateTime>

// Получаем текущий момент времени в формате UTC
QDateTime nowUtc = QDateTime::currentDateTimeUtc();

// Проверка: какая спецификация у объекта?
if (nowUtc.timeSpec() == Qt::UTC) {
    // Этот объект хранит время без привязки к локальным часовым поясам
}

2. Преобразование локального времени в UTC
Если у вас уже есть объект с локальным временем (например, из виджета или системы), перевести его в UTC очень просто:

QDateTime local = QDateTime::currentDateTime(); // Местное время (например, RTZ 6)
QDateTime utc = local.toUTC();                  // Конвертация в UTC


3. Форматирование UTC-времени для сохранения (ISO 8601)
Для записи в базу данных или отправки по сети лучше всего использовать международный стандарт ISO 8601. 
В Qt6 для этого есть встроенный метод:

// Результат будет в формате: "2023-10-27T14:30:05Z" (Z означает UTC)
QString s = utc.toString(Qt::ISODate); 


4. Обратная загрузка из строки
Когда вы читаете время из БД или файла, важно сразу пометить его как UTC:

QString storedString = "2023-10-27T14:30:05Z";
QDateTime dateTime = QDateTime::fromString(storedString, Qt::ISODate);

// Qt поймет 'Z' в конце строки и установит спецификацию Qt::UTC автоматически


Резюме: Правильная стратегия

Внутри программы: Всегда храните и передавайте объекты QDateTime со спецификацией Qt::UTC.
В интерфейсе (UI): Конвертируйте UTC в местное время только в момент отображения пользователю:

label->setText(utcTime.toLocalTime().toString(QLocale::system(), QLocale::ShortFormat));


