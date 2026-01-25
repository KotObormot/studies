//#include <QCoreApplication>
#include <QApplication>
#include <QWidget>
#include <QLabel>
//#include <iostream>

int main(int argc, char *argv[])
{
    /*QCoreApplication a(argc, argv);

    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.

    std::cout << "Hello METANIT.COM!" << std::endl;
    qDebug() << qApp->arguments();      // список параметров, переданных в командной строке

    QString str("строка");
    qDebug() << str.size(); // 6
    qDebug() << str.length(); // 6

    qDebug() << "The End" << "!" << "!";
    return a.exec();*/

    QApplication app(argc, argv); // создаем объект приложения
    QWidget widget;               // создаем виджет
    // настраиваем заголовок окна
    widget.setWindowTitle("Qt на METANIT.COM");
    widget.setMinimumHeight(380);  // высота окна
    widget.setMinimumWidth(500);  // ширина окна

    QLabel label{&widget};      // создаем текстовую метку и передаём указатель на виджет, который представляет контейнер и в который будет добавляться метка. То есть в данном случае метка добавляется в контейнер widget.
    label.setText("Hello METANIT.COM"); // установка текста метки

    QLabel label2{&widget};
    label2.setText("**************************************************************");

    widget.show();                // отображаем виджет

    return app.exec();           // запуск приложения

}
