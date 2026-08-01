#include <QCoreApplication>
//#include <QTextStream>
#include <iostream>

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

    QTextStream out (stdout);

    QString str1 = "The night train";
    out << str1 << Qt::endl;

    QString str2("An yellow rose");
    out << str2 << Qt::endl;

    std::string s1 = "The blue sky";
    std::cout << s1 << " = ";
    QString str3 = s1.c_str();
    out << str3 << Qt::endl;

    std::string s2 = "A thick fog";
    std::cout << s2 << " = ";
    QString str4 = QString::fromLatin1(s2.data(), s2.size());
    out << str4 << Qt::endl;

    char s3[] = "A deep forest";
    std::cout << s3 << " = ";
    QString str5(s3);
    out << str5 << Qt::endl;

    return a.exec();
}
