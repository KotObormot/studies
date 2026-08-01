#include <QCoreApplication>
#include <QTextStream>
#include <QString>
#include <QFile>

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

    //toHtmlEscaped();
    // <> & ""
    QFile file("text.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        qWarning("Cannot open file for reading");
        return 1;
    }

    QTextStream in(&file);

    QString allText = in.readAll();
    out << "1 =====================" << allText.toHtmlEscaped() << Qt::endl;

    out << "2 =====================" << allText/*.toHtmlEscaped()*/ << Qt::endl;
    file.close();

    return a.exec();
}
