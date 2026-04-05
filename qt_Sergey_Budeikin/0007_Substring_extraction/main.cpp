#include <QCoreApplication>
#include <QTextStream>
//#include <QStringView>
#include <QStringRef>

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

    QString str = "The night train";

    out << str << Qt::endl;
    out << str.right(5) << Qt::endl;
    out << str.left(3) << Qt::endl;
    out << str.mid(4, 5) << Qt::endl;
    out << str.left(4) << str.mid(4, 6) << str.right(5) << Qt::endl;

    QString strRight = str.right(5);
    out << strRight << Qt::endl;

    ////////////////////////////////////
    QString str2("The big apple");
    out << str2 << Qt::endl;
    QStringRef substr2(&str2, 2, 15);
    out << substr2.toString() << Qt::endl;

    return a.exec();
}
