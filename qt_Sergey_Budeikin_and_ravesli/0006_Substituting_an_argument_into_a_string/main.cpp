#include <QCoreApplication>
#include <QTextStream>

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

    QString s1 = "There are %1 white roses";
    int n = 15;
    out << s1.arg(n) << Qt::endl;

    QString s2 = "The tree is %2 m high";
    double h = 4.47;
    out << s2.arg(h) << Qt::endl;

    QString s3 = "We have %1 lemons and %2 oranges";
    int ln = 10;
    int on = 5;
    out << s3.arg(ln).arg(on) << Qt::endl;

    char lnCh[] = "ten";
    char onCh[] = "five";
    out << s3.arg(lnCh).arg(onCh) << Qt::endl;

    return a.exec();
}
