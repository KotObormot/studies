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

    int digits = 0;
    int letters = 0;
    int spaces = 0;
    int puncts = 0;
    int other = 0;

    QString str = "7 white, 3 red roses.\n\t";

    foreach(QChar s, str) {
        if(s.isDigit()) {
            digits++;
        } else if(s.isLetter()) {
            letters++;
        } else if(s.isSpace()) {
            spaces++;
        } else if(s.isPunct()) {
            puncts++;
        } else {
            other++;
        }
    }

    /*out << "digits == " << digits << Qt::endl
        << "letters == " << letters << Qt::endl
        << "spaces == " << spaces << Qt::endl
        << "puncts == " << puncts << Qt::endl
        << "other == " << other << Qt::endl;
    */
    out << QString("There are: \t%1 characters, incl.\n\t%2 digits,\n\t%3 letters,\n\t%4 spaces,\n\t%5 puncts,\n\t%6 others.")
               .arg(str.size()).arg(digits).arg(letters).arg(spaces).arg(puncts).arg(other) << Qt::endl;

    return a.exec();
}
