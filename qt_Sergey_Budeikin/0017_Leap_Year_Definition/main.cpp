#include <QCoreApplication>
#include <QTextStream>
#include <QDate>
#include <QTime>

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

    QList<int> years({2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2019, 2020, 2021});
    foreach (int year, years) {
        if(QDate::isLeapYear(year)) {
            out << year << " is a leap year # " << QDate::isLeapYear(year) << "." << Qt::endl;
        } else {
            out << year << " isn't a leap year # " << QDate::isLeapYear(year) << "." << Qt::endl;
        }
    }

    return a.exec();
}
