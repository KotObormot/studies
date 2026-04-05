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

    QString str = "There are many stars.";
    out << str << Qt::endl;

    foreach (QChar qc, str) {
        out << qc << " ";
    }
    out << Qt::endl;

    for(QChar* it = str.begin(); it != str.end(); ++it) {
        out << *it << "-";
    }
    out << Qt::endl;

    for(int i = 0; i < str.size(); ++i) {
        out << str.at(i) << "_";
    }
    out << Qt::endl;

    for(int j = 0; j < str.length(); ++j) {
        out << str[j] << "^";
    }
    out << Qt::endl;

    return a.exec();
}
