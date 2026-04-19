#include <QCoreApplication>
#include <QTextStream>
#include <QDate>
#include <QTime>

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

    /*out.setCodec("CP866");
     * в чем причина ошибки no member named setcodec in qtextstream
Причина ошибки заключается в том, что метод setCodec() был удален в Qt 6. В новой версии библиотеки класс QTextCodec заменен на QStringConverter,
а для управления кодировкой в потоке QTextStream теперь используется другой метод.
Как исправить
В зависимости от ваших задач, используйте один из следующих способов:

    Если нужна стандартная кодировка (например, UTF-8):
    Используйте метод setEncoding(), который принимает значения из перечисления QStringConverter::Encoding.
    cpp

    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8); // Вместо setCodec

    Используйте код с осторожностью.
    Примечание: в Qt 6 кодировка UTF-8 используется в QTextStream по умолчанию.
    Если нужна системная кодировка:
    cpp

    out.setEncoding(QStringConverter::System);

    Используйте код с осторожностью.
    Если нужно использовать старый QTextCodec (например, для CP1251):
    Класс QTextCodec перенесен в отдельный модуль совместимости core5compat.
    Поскольку setCodec в самом QTextStream больше нет, данные нужно конвертировать вручную перед записью или после чтения:
        Добавьте в .pro файл: QT += core5compat.
        Подключите: #include <QtCore5Compat/QTextCodec>.
        Используйте кодек для преобразования:
        cpp

        QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
        QByteArray encodedData = codec->fromUnicode(myString); // Для записи
        QString decodedString = codec->toUnicode(fileData);   // Для чтения

        Используйте код с осторожностью.


Почему это произошло
Разработчики Qt упростили систему работы с текстом, сделав упор на современные стандарты Unicode.
Новый класс QStringConverter поддерживает меньше кодировок (в основном семейство UTF и Latin1),
а поддержка устаревших кодировок была вынесена в модуль совместимости для облегчения основного ядра библиотеки.
----------------------
Для вывода текста в кодировке CP866 (стандартная кодировка консоли Windows) в Qt 6 есть два пути.
Основная сложность в том, что в новом классе QStringConverter этой кодировки нет «из коробки», а метод setCodec из QTextStream удален.
Способ 1: Использование модуля Core5Compat (Рекомендуемый)
Это самый простой способ вернуть поддержку старых кодировок, включая IBM 866.

    Настройте проект:
        Если используете CMake, добавьте в CMakeLists.txt:
        cmake

        find_package(Qt6 REQUIRED COMPONENTS Core5Compat)
        target_link_libraries(mytarget PRIVATE Qt6::Core5Compat)

        Используйте код с осторожностью.
        Если используете qmake (.pro файл):
        pro

        QT += core5compat

        Используйте код с осторожностью.
    Напишите код:
    Поскольку в QTextStream больше нет метода setCodec, вам нужно вручную перекодировать строку перед отправкой в поток.
    cpp

    #include <QCoreApplication>
    #include <QTextStream>
    #include <QtCore5Compat/QTextCodec> // Обратите внимание на путь к заголовку

    int main(int argc, char *argv[]) {
        QCoreApplication a(argc, argv);

        QTextStream out(stdout);
        QString text = "Привет, мир! (CP866)";

        // Получаем кодек для CP866
        QTextCodec *codec = QTextCodec::codecForName("IBM 866");

        if (codec) {
            // Конвертируем QString в массив байт нужной кодировки
            QByteArray encodedText = codec->fromUnicode(text);
            // Выводим в поток как сырые данные
            out << encodedText << Qt::endl;
        }

        return 0;
    }

    Используйте код с осторожностью.

Способ 2: Использование QStringEncoder (Для Qt 6.6+)
Если вы используете версию Qt 6.6 и выше, а библиотека собрана с поддержкой ICU, вы можете использовать новый механизм без старых модулей.
cpp

#include <QStringConverter>

// ...
QString text = "Текст в CP866";
auto encoder = QStringEncoder("IBM866"); // Работает, если есть ICU

if (encoder.isValid()) {
    QByteArray encoded = encoder.encode(text);
    // Вывод в файл или консоль через QFile::write() или QTextStream
    out << encoded;
}

Используйте код с осторожностью.
Коротко о главном:

    В Qt 6 кодировка CP866 не поддерживается стандартным перечислением QStringConverter::Encoding.
    Метод setCodec в QTextStream отсутствует, теперь нужно конвертировать строку в QByteArray перед выводом.
    Проще всего подключить Core5Compat и использовать QTextCodec для получения QByteArray*/

    //out.setEncoding(QStringConverter::Utf8);
    out.setEncoding(QStringConverter::System);
    QDate dt1(2016, 5, 15);
    out << "The date is " << dt1.toString() << Qt::endl;

    QDate dt2;
    dt2.setDate(2017, 4, 10);
    out << "The date2 is " << dt2.toString() << Qt::endl;

    QTime tm1(13, 1, 25, 40);
    out << "The time is " << tm1.toString() << Qt::endl;

    QTime tm2;
    tm2.setHMS(22, 02, 59, 52);
    out << "The time2 is " << tm2.toString("hh-mm-ss,zzz") << Qt::endl;
    out << "The time2 is " << tm2.toString("hh-mm-ss,z") << Qt::endl;

    out << "=====================\n" << Qt::endl;

    QDate cd = QDate::currentDate();
    QTime ct = QTime::currentTime();
    out << "It's " << cd.toString("dd.MM.yyyy") << " " << ct.toString("hh:mm:ss,z") << " now." << Qt::endl;

    return a.exec();
}
