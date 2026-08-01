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

    QString str = "Lovely";
    out << str << Qt::endl;

    str.append(" season");
    out << str << Qt::endl;

    QString str1 = str.remove(10, 3);
    out << str1 << Qt::endl;

    QString str2 = str.replace(7, 3, "girl.");
    out << str2 << Qt::endl;

    str2.clear();
    if(str2.isEmpty()) {
        out << "The string is empty. " << str2.size() << " " << str2.isEmpty() << Qt::endl;
    } else {
        out << str2 << " " << str2.length() << " " << str2.isEmpty() << Qt::endl;
    }

    return a.exec();
}
