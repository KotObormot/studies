#include <QCoreApplication>
#include <QTextStream>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QTimeZone>
#include <QLocale>
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

    QList<QDate> dates({QDate(2019, 3, 7), QDate(2021, 2, 31), QDate(2016, 5, 9), QDate(2020, 2, 29)});

    for(int i = 0; i < dates.size(); ++i) {
        if(dates.at(i).isValid()) {
            out << "Valid " << dates.at(i).toString() << Qt::endl;
        } else {
            out << "Not valid" << Qt::endl;
        }
    }

    /*********************************************************/

    out << Qt::endl << "**********************************************\n" << Qt::endl;

    QDate dt(2021, 10, 17);
    qint64 days = 55;
    QDate nd = dt.addDays(days);
    out << "The new date is " << nd.toString() << Qt::endl;
    out << "In " << days << " days it will be " << QDate::currentDate().addDays(days).toString() << Qt::endl;

    int months = 5;
    out << "In " << months << " months it will be " << QDate::currentDate().addMonths(months).toString() << Qt::endl;

    // Пример для западного Рождества
    QDate christmasWestern(2026, 12, 25);
    // Пример для православного Рождества
    QDate christmasOrthodox(2027, 1, 7);
    out << "Catholic Christmas will be in " << QDate::currentDate().daysTo(christmasWestern) << " days "
        << "and Orthodox Christmas will be in " << QDate::currentDate().daysTo(christmasOrthodox) <<  " days."
        << Qt::endl;

    return a.exec();
}
