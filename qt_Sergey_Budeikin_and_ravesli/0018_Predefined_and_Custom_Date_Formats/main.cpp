#include <QCoreApplication>
#include <QTextStream>
#include <QDate>
#include <QTime>
#include <QLocale>

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
    out << "0) " << "Current date is " << cd.toString() << Qt::endl;

    out << "1) " << "Current date is " << cd.toString(Qt::TextDate) << Qt::endl;

    out << "2) " << "Current date is " << cd.toString(Qt::ISODate) << Qt::endl;

    // out << "3) " << "Current date is " << cd.toString(Qt::SystemLocalShortDate) << Qt::endl; в Qt 6 (как и в Qt 5.15+) константы Qt::SystemLocalShortDate не существует.
    //Вместо старого подхода теперь нужно использовать класс QLocale. Он отвечает за то, как даты выглядят в конкретном регионе.
    // Вместо Qt::SystemLocalShortDate
    // C++:
    QString date = QLocale::system().toString(QDate::currentDate(), QLocale::ShortFormat);
    //QML:
    //let dateString = new Date().toLocaleDateString(Qt.locale(), Locale.ShortFormat)
    out << "3) " << "Current local date is " << date << Qt::endl;

    out << "4) " << "Текущая локальная дата: " << QLocale::system().toString(cd, QLocale::LongFormat) << Qt::endl;

    out << "5) " << "Current global date is " << QLocale("en_US").toString(cd, QLocale::ShortFormat) << Qt::endl;

    out << "6) " << "Current global date is " << QLocale("en_US").toString(cd, QLocale::LongFormat) << Qt::endl;

    //out << "1) " << "Current date is " << cd.toString(Qt::DefaultLocaleShortDate) << Qt::endl;

    out << "7) " << "Current date is " << cd.toString("dd.MM.yy, ddd") << Qt::endl;

    out << "8) " << "Current date is " << cd.toString("MMM dd, yyyy, dddd") << Qt::endl;

    out << "9) " << "Current date is " << cd.toString("MMMM dd, yyyy, dddd") << Qt::endl;

    out << "10) " << "Current date is " << cd.toString("MM/dd/yy, ddd") << Qt::endl;

    out << "11) " << "Current date is " << cd.toString("M/d/yy, ddd") << Qt::endl;

    out << "12) " << "Current date is " << cd.toJulianDay() << Qt::endl;


    return a.exec();
}
