#include <QCoreApplication>
#include <QTextStream>
#include <QDateTime>
#include <ctime>

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

    time_t t = time(0);
    out << t << Qt::endl;

    //QDateTime dt;
    //dt.setTime_t(t);

    qint64 timestamp = QDateTime::currentSecsSinceEpoch();
    out << timestamp << Qt::endl;

    //Если нужны миллисекунды
    qint64 msTimestamp = QDateTime::currentMSecsSinceEpoch();
    out << msTimestamp << Qt::endl;

    //Из конкретного объекта даты/времени
    QDateTime dt = QDateTime::currentDateTime();
    qint64 unixTime = dt.toSecsSinceEpoch();
    out << unixTime << Qt::endl;

    //Если у вас есть число и нужно превратить его в понятную дату:
    qint64 timestamp1 = 1715456789;
    QDateTime dt1 = QDateTime::fromSecsSinceEpoch(timestamp1);
    out << dt1.toString("dd.MM.yyyy hh:mm:ss t") << Qt::endl;

    qint64 timestamp2 = 2;
    QDateTime dt2 = QDateTime::fromSecsSinceEpoch(timestamp2);
    out << dt2.toUTC().toString("dd.MM.yyyy hh:mm:ss t") << Qt::endl;

    return a.exec();
}
