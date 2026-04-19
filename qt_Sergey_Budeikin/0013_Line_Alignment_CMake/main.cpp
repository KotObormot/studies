#include <QCoreApplication>
#include <QTextStream>
#include <QString>

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

    QString field1 = "Name: ";
    QString field2 = "Occupation: ";
    QString field3 = "Residence: ";
    QString field4 = "Marital status: ";

    int widht = field4.size();

    out << field1.rightJustified(widht, ' ') << "Robert\n"
        << field2.rightJustified(widht, ' ') << "Programmer\n"
        << field3.rightJustified(widht, ' ') << "New York\n"
        << field4.rightJustified(widht, ' ') << "Single\n"
        << Qt::endl;

    out << field1.leftJustified(widht, '.') << "John\n"
        << field2.leftJustified(widht, '.') << "Manager\n"
        << field3.leftJustified(widht, '.') << "Washington\n"
        << field4.leftJustified(widht, '.') << "Married\n"
        << Qt::endl;

    return a.exec();
}
