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

    QString str = "Eagle";
    out << str << Qt::endl;
    out << str[0] << str[1] << str[2] << str[3] << str[4] << Qt::endl;
    out << str.at(0) << str.at(1) << str.at(2) << str.at(3) << str.at(4) << Qt::endl;

    return a.exec();
}
