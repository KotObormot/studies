#include <QCoreApplication>
#include <QTextStream>
#include <QVector>

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

    QVector<int> vals = {1, 2, 3 , 4, 5};

    out << "The size of the vector is " << vals.size() << ";" << Qt::endl;
    out << "The first item is " << vals.first() << ";" << Qt::endl;
    out << "The last item is " << vals.last() << ";" << Qt::endl;

    vals.append(6);
    vals.prepend(0);
    out << "The new size of the vector is " << vals.size() << ";" << Qt::endl;
    out << "The new first item is " << vals.first() << ";" << Qt::endl;
    out << "The new last item is " << vals.last() << ";" << Qt::endl;

    out << "All of elements ov the new vector: ";
    foreach (int val, vals) {
        out << val << "; ";
    }
    out << Qt::endl;

    return a.exec();
}
