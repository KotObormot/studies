#include <QCoreApplication>
#include <QTextStream>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QLocale>
#include <QString>
#include <QDebug>

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

    QDate cd = QDate::currentDate();
    int wd = cd.dayOfWeek();
    out << "Today is " << cd.toString() << " " << wd << Qt::endl;
    //out << QDate::ShortDateName(wd) << Qt::endl; В Qt 6 статического метода QDate::shortMonthName() (или shortDayName()) больше не существует

    QLocale locale = QLocale::system();
    QLocale london = QLocale("en_GB");
    QLocale berlin = QLocale("de_DE");
    out << "Today is " << locale.dayName(wd, QLocale::LongFormat) << " = "
                       << locale.dayName(wd, QLocale::ShortFormat) << " = "
        << locale.dayName(wd, QLocale::NarrowFormat) << " = "
        << london.dayName(wd, QLocale::LongFormat) << " = "
        << berlin.dayName(wd, QLocale::LongFormat)
        << Qt::endl;

    out << Qt::endl << "---------------------------------------------" << Qt::endl << Qt::endl;

    out << "Today is " << berlin.monthName(cd.month(), QLocale::LongFormat) << Qt::endl;

    out << Qt::endl << "---------------------------------------------" << Qt::endl << Qt::endl;
    QList<QString> months;
    months.append("Janury");
    months.append("February");
    months.append("March");
    months.append("April");
    months.append("May");
    months.append("Junу");
    months.append("July");
    months.append("August");
    months.append("September");
    months.append("October");
    months.append("November");
    months.append("December");

    QDate dt1(2018, 9, 18);
    QDate dt2(2018, 5, 10);
    QDate dt3(2018, 3, 15);
    QDate dt4(2018, 2, 1);
    QDate dt5(2020, 2, 1);

    out << "There are " << dt1.daysInMonth() << " days in " << months.at(dt1.month() - 1) << Qt::endl; // Qt 5
    out << "There are " << dt1.daysInMonth() << " days in " << london.monthName(dt1.month(), QLocale::LongFormat) << Qt::endl; // Qt6
    out << "There are " << dt4.daysInMonth() << " days in " << london.monthName(dt4.month(), QLocale::LongFormat) << Qt::endl; // Qt6
    out << "There are " << dt5.daysInMonth() << " days in " << berlin.monthName(dt5.month(), QLocale::LongFormat) << Qt::endl; // Qt6

    out << Qt::endl << "---------------------------------------------" << Qt::endl << Qt::endl;
    out << "There are " << dt4.daysInYear() << " days in year " << dt4.year() << " == " << QString::number(dt4.year()) << Qt::endl;
    out << "There are " << dt5.daysInYear() << " days in year " << dt5.year() << " == " << QString::number(dt5.year()) << Qt::endl;

    return a.exec();
}
