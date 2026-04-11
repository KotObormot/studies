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

    QString s1 = "15";
    QString s2 = "20";
    out << s1 + s2 << Qt::endl;
    out << s1.toInt() + s2.toInt() << Qt::endl;

    int n1 = 50;
    int n2 = 35;
    out << n1 + n2 << Qt::endl;
    QString s3, s4;
    out << s3.setNum(n1) + s4.setNum(n2) << Qt::endl;

    out << QString::number(n1) + QString::number(n2) << Qt::endl;

    return a.exec();
}
