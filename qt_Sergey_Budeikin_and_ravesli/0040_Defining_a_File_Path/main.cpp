#include <QCoreApplication>
#include <QTextStream>
//#include <QFile>
#include <QFileInfo>
//#include <QDir>

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
        qWarning("Usage: file_times file");
        return 1;
    }

    QString fileName = argv[1];

    // Определяем путь к файлу
    QFileInfo fileInfo(fileName);

    QString absPath = fileInfo.absoluteFilePath();   // возвращаем абсолютный путь, включающий имя файла
    QString baseName = fileInfo.baseName();         // возвращаем базовое имя: имя файла без пути
    QString compBaseName = fileInfo.completeBaseName(); // возвращаем полное базовое имя: все символы в имени файла до последней точки (но не включая её)
    QString fileName1 = fileInfo.fileName();    //возвращаем имя файла, которое является базовым именем + расширение
    QString suffix = fileInfo.suffix(); // возвращаем расширение файла, которое состоит из всех символов в базовом имени файла + расширение после последнего символа точки (но не включая её)
    QString compSuffix = fileInfo.completeSuffix(); //возвращаем расширение файла, которое состоит из всех символов в базовом имени файла + расширение после первого символа точки (но не включая её)

    //PRINT
    out << "Absolute file path\t" << absPath << Qt::endl;
    out << "Base name\t" << baseName << Qt::endl;
    out << "Complete base name\t" << compBaseName << Qt::endl;
    out << "File name\t" << fileName1 << Qt::endl;
    out << "Suffix\t" << suffix << Qt::endl;
    out << "Whole suffix\t" << compSuffix << Qt::endl;

    // EXIT
    return 0;

    return a.exec();
}
