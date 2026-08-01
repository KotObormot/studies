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

    const int STR_EQUL = 0;

    QTextStream out(stdout);

    QString a1 = "Rain";
    QString b = "rain";
    QString c = "rain\n";

    // Сравненик с чувствительным регистром
    if(QString::compare(a1, b) == STR_EQUL) {
        out << "a, b are EQUAL" << Qt::endl;
    } else {
        out << "a, b are NOT EQUAL" << Qt::endl;
    }

    // Сравненик с нечувствительным регистром
    if(QString::compare(a1, b, Qt::CaseInsensitive) == STR_EQUL) {
        out << "a, b are EQUAL" << Qt::endl;
    } else {
        out << "a, b are NOT EQUAL" << Qt::endl;
    }

    //
    if(QString::compare(b, c) == STR_EQUL) {
        out << "b, c are EQUAL" << Qt::endl;
    } else {
        out << "b, c are NOT EQUAL" << Qt::endl;
    }

    // Удаляем символ переноса строки
    c.chop(1);
    //out << c;
    if(QString::compare(b, c) == STR_EQUL) {
        out << "b, c are EQUAL" << Qt::endl;
    } else {
        out << "b, c are NOT EQUAL" << Qt::endl;
    }

    return a.exec();
}
