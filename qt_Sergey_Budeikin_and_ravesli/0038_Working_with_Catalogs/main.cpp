#include <QCoreApplication>
#include <QTextStream>
#include <QDir>

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

    QDir dir;

    // Метод mkdir() создает каталог, при этом возвращая true, если каталог был успешно создан
    if(dir.mkdir("mydir")) {
        out << "mydir succesfully created" << Qt::endl;
    }

    QString mydir2 = "mydir2";
    dir.mkdir(mydir2);
    out << mydir2 << " successfully created" << Qt::endl;

    // Метод exists() проверяет наличие каталога
    if(dir.exists("mydir1")) {
        dir.rename(mydir2, "newdir");                // метод rename() переименовывает каталог
        out << mydir2 << " has been successfully renamed to newdir " << Qt::endl;
    } else {
        out << "mydir1 does not exist" << Qt::endl;
    }

    // Создаем новый каталог и все необходимые родительские каталоги
    dir.mkpath("temp/newdir1");
    dir.mkpath("temp/" + mydir2);

    //  EXIT
    return 0;

    return a.exec();
}
