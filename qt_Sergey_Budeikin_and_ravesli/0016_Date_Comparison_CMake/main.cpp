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

    QDate dt1(2016, 5, 6);
    QDate dt2(2015, 5, 6);

    if(dt1 < dt2) {
        out << dt1.toString("dd.MM.yyyy") << " comes before " << dt2.toString() << Qt::endl;
    } else if (dt1 > dt2) {
        out << dt2.toString("dd.MM.yyyy") << " comes before " << dt1.toString() << Qt::endl;
    } else {
        out << dt2.toString("dd.MM.yyyy") << " == " << dt1.toString() << Qt::endl;;
    }

    return a.exec();
}
