#include <QCoreApplication>

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

    QString str1 = "Eagle";
    QString str2 = "Eagle\n";
    QString str3 = "Eagle ";
    QString str4 = "Орёл";

    out << str1 << "; " << str1.size() << " == " << str1.count() << " == " << str1.length() << Qt::endl
        << str2 << "; " << str2.size() << " == " << str2.count() << " == " << str2.length() << Qt::endl
        << str3 << "; " << str3.size() << " == " << str3.count() << " == " << str3.length() << Qt::endl
        << str4 << "; " << str4.size() << " == " << str4.count() << " == " << str4.length() << Qt::endl;


    return a.exec();
}
