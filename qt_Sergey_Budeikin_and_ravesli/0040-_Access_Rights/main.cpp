#include <QCoreApplication>
#include <QTextStream>
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

    if(argc != 2) {
        qWarning("Usage: permissions file");
        return 1;
    }

    QString filename = argv[1];

    // Получаем перечисление флагов разрешений
    QFile::Permissions ps = QFile::permissions(filename);
    /*Это предупреждение от статического анализатора кода Clang.
     * Оно означает, что вы создали переменную с именем ps и присвоили ей начальное значение,
     * но в дальнейшем коде никогда не читаете это значение перед тем, как перезаписать переменную новой информацией или завершить работу программы*/

    // Эта строка динамически строится на основе заданных разрешений
    QString fper;

    // Во всех условиях, приведенных ниже, используем оператор &, чтобы определить, из каких возможных флагов прав состоит возвращаемое перечисление

    if (ps & QFile::ReadOwner) {
        fper.append('r');
    } else {
        fper.append('-');
    }

    if (ps & QFile::WriteOwner) {
        fper.append('w');
    } else {
        fper.append('-');
    }

    if (ps & QFile::ExeOwner) {
        fper.append('x');
    } else {
        fper.append('-');
    }

    if (ps & QFile::ReadGroup) {
        fper.append('r');
    } else {
        fper.append('-');
    }

    if (ps & QFile::WriteGroup) {
        fper.append('w');
    } else {
        fper.append('-');
    }

    if (ps & QFile::ExeGroup) {
        fper.append('x');
    } else {
        fper.append('-');
    }

    if (ps & QFile::ReadOther) {
        fper.append('r');
    } else {
        fper.append('-');
    }

    if (ps & QFile::WriteOther) {
        fper.append('w');
    } else {
        fper.append('-');
    }

    if (ps & QFile::ExeOther) {
        fper.append('x');
    } else {
        fper.append('-');
    }

    //PRINT
    out << fper << Qt::endl;

    // EXIT
    return 0;

    return a.exec();
}
