#include <QCoreApplication>
#include <QTextStream>
#include <QDate>
#include <QTime>
#include <QLocale>
#include <QTimeZone>
#include <QDateTime>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.
    QTextStream out(stdout);

    QLocale localSystem = QLocale::system();
    QLocale localEnUS = QLocale("en_US");
    QLocale localEnGB = QLocale("en_GB");
    QDateTime ct = QDateTime::currentDateTime();


    out << "0) " << "Current time is " << ct.toString() << Qt::endl;
    out << "1) " << "Current time is " << ct.toString(Qt::TextDate) << Qt::endl;
    out << "2) " << "Current time is " << ct.toString(Qt::ISODate) << Qt::endl;

    out << "4) " << "Текущая локальное время: " << localSystem.toString(ct, QLocale::LongFormat) << Qt::endl;
    out << "5) " << "Current time is " << localEnUS.toString(ct, QLocale::ShortFormat) << Qt::endl;
    out << "5.1) " << "Current time is " << localEnGB.toString(ct, QLocale::LongFormat) << Qt::endl;
    out << "6) " << "Current time is " << QLocale("de_DE").toString(ct, QLocale::LongFormat) << Qt::endl;

    out << "7) " << "Current time is " << ct.toString("hh:mm:ss,zzz") << Qt::endl;
    out << "7) " << "Current time is " << ct.toString("H:m:s,z AP") << Qt::endl;
    out << "7.1) " << "Current time is " << ct.toString("h:m ap t") << Qt::endl;

    QTimeZone rtz6Zone("Asia/Krasnoyarsk");
    QDateTime krasnoyarskTime = ct.toTimeZone(rtz6Zone);
    out << "8) " << "Время в Красноярске " << QLocale("ru_RU").toString(krasnoyarskTime, QLocale::LongFormat) << Qt::endl;
    /*********************************************************************************************************************/

    //В Qt6 хранение времени в UTC является «золотым стандартом»:
    // Получаем текущий момент времени в формате UTC
    QDateTime nowUtc = QDateTime::currentDateTimeUtc();

    // Проверка: какая спецификация у объекта?
    if (nowUtc.timeSpec() == Qt::UTC) {
        // Этот объект хранит время без привязки к локальным часовым поясам
    }

    QDateTime local = QDateTime::currentDateTime(); // Местное время (например, RTZ 6)
    QDateTime utc = local.toUTC();                  // Конвертация в UTC

    // Результат будет в формате: "2023-10-27T14:30:05Z" (Z означает UTC)
    QString s = utc.toString(Qt::ISODate);
    out << "9) " << "Current UTC is " << s << Qt::endl;

    QString storedString = "2023-10-27T14:30:05Z";
    QDateTime storedDateTime = QDateTime::fromString(storedString, Qt::ISODate);
    // Qt поймет 'Z' в конце строки и установит спецификацию Qt::UTC автоматически

    out << "10) " << "Stored time is " << QLocale("en_EN").toString(storedDateTime, QLocale::LongFormat) << Qt::endl;

    return a.exec();
}
