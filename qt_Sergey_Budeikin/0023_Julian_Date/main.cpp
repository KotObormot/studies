#include <QCoreApplication>
#include <QTextStream>
#include <QDateTime>
#include <QDate>


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

    QDateTime cdt = QDateTime::currentDateTime();
    out << "Current date == " << cdt.toString(Qt::ISODate) << " == " << cdt.date().toJulianDay() << Qt::endl;

    qint64 jd = 2460265; // Пример: 15 ноября 2023
    QDate date = QDate::fromJulianDay(jd);
    out << "New date " << date.toString() << Qt::endl;

    out << Qt::endl << "---------------------------------------------\n" << Qt::endl;

    QDate cd = QDate::currentDate();
    QDate borodinoDay(1812, 9, 7);
    QDate austerlitzDay(1805, 12, 2);
    out << borodinoDay.toJulianDay() - austerlitzDay.toJulianDay() << " == "
        << austerlitzDay.daysTo(borodinoDay) << " days." << Qt::endl;

    out << "Since Slavkov " << - austerlitzDay.toJulianDay() + cd.toJulianDay()
        << " days, since Borodino" << - borodinoDay.toJulianDay() + cd.toJulianDay() << " days"
        << Qt::endl;

    return a.exec();
}
