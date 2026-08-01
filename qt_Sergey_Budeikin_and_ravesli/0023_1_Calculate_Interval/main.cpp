#include <QCoreApplication>

#include <QDate>
#include <QDebug>

struct DateInterval {
    int years;
    int months;
    int days;
};

DateInterval calculateInterval(QDate startDate, QDate endDate) {
    // Если даты перепутаны местами, меняем их, чтобы startDate всегда была раньше
    bool swapped = false;
    if (startDate > endDate) {
        std::swap(startDate, endDate);
        swapped = true;
    }

    int years = 0;
    int months = 0;
    int days = 0;

    // 1. Считаем полные годы
    years = endDate.year() - startDate.year();
    if (startDate.addYears(years) > endDate) {
        years--;
    }
    QDate current = startDate.addYears(years);

    // 2. Считаем полные месяцы
    while (current.addMonths(months + 1) <= endDate) {
        months++;
    }
    current = current.addMonths(months);

    // 3. Остаток — это дни
    days = current.daysTo(endDate);

    return {years, months, days};
}

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
    QDate d1(1960, 1, 1); // my birthday
    QDate d2 = QDate::currentDate();

    DateInterval interval = calculateInterval(d1, d2);

    qDebug() << QString("Прошло: %1 лет, %2 месяцев и %3 дней")
                    .arg(interval.years)
                    .arg(interval.months)
                    .arg(interval.days);

    return a.exec();
}
