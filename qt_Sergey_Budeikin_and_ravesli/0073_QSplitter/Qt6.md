# Чем в Qt 6 заменить    QDesktopWidget

В Qt 6 класс QDesktopWidget был полностью удален. 

Поскольку в вашем текущем коде этот заголовочный файл вообще не используется (вы просто создаете и показываете окно Splitter), вы можете просто удалить строчку 

        #include <QDesktopWidget>.

Если же в полной версии вашего кода вы планируете использовать функции QDesktopWidget (например, для центрирования окна или получения размеров экрана), его нужно заменить на класс QScreen или QGuiApplication.
Вот исправленный код вашей программы:

        #include <QApplication>
        #include "splitter.h"
        
        int main(int argc, char *argv[]) {
        
            QApplication app(argc, argv);  
        
            Splitter window;
     
            window.resize(350, 300);
            window.setWindowTitle("QSplitter");
            window.show();
      
            return app.exec();
        }

----------

## Как заменить методы QDesktopWidget в Qt 6 (на будущее)
Если вы будете дописывать код и вам понадобятся функции экрана, используйте следующие замены:

- Вместо 

        #include <QDesktopWidget> подключайте 

        #include <QScreen> и #include <QGuiApplication>. [1, 2] 
* Размер первичного экрана:
    * Было: QApplication::desktop()->geometry()
    * Стало: QGuiApplication::primaryScreen()->geometry()
* Разрешение экрана (ширина и высота):
    * Было: QApplication::desktop()->width()
    * Стало: QGuiApplication::primaryScreen()->size().width() [3] 
* Доступная геометрия (без панели задач):
    * Было: QApplication::desktop()->availableGeometry()
    * Стало: QGuiApplication::primaryScreen()->availableGeometry() [4] 

Если вы хотите отцентрировать ваше окно на экране в Qt 6, сообщите мне, и я помогу вам написать функцию центрирования или подскажу, как адаптировать другие старые методы Qt 5 под новую версию.

https://share.google/aimode/cRknLEcKbZ7mh0Lf2

# ẞ
