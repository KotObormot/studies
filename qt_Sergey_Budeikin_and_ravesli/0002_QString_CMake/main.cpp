#include <QCoreApplication>
//#include <QTextStream>

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
    QString str = "love";

    str.append(" chess!");
    str.prepend("I ");

    out << str << Qt::endl;

    out << "1) The string has " << str.count() << " characters.\n";
    out << "2) The string has " << str.size() << " characters.\n";
    out << "3) The string has " << str.length() << " characters.\n";

    out << str.toUpper() << Qt::endl;
    out << str.toLower() << "\n";

    out << Qt::endl;
    return a.exec();
}
