# Kак заставить градиент плавно переливаться?

- [AI](https://www.google.com/search?q=%D0%9F%D0%BE%D1%87%D0%B5%D0%BC%D1%83+%D0%B2+%D0%BA%D0%BE%D0%B4%D0%B5+%0D%0A%0D%0A++++QPainter+*painter+%3D+new+QPainter%28this%29%3B%0D%0A%0D%0A++++QLinearGradient+*gradVer+%3D+new+QLinearGradient%280%2C+20%2C+0%2C+110%29%3B%0D%0A%0D%0A++++gradVer-%3EsetColorAt%280.1%2C+Qt%3A%3Ablack%29%3B%0D%0A++++gradVer-%3EsetColorAt%280.5%2C+Qt%3A%3Ayellow%29%3B%0D%0A++++gradVer-%3EsetColorAt%280.9%2C+Qt%3A%3Ablue%29%3B%0D%0A%0D%0A++++painter-%3EfillRect%2820%2C+20%2C+1000%2C+500%2C+gradVer%29%3B%0D%0A++++%0D%0A++++%D0%BE%D1%88%D0%B8%D0%B1%D0%BA%D0%B0+%D0%B2+%D0%BF%D0%BE%D1%81%D0%BB%D0%B5%D0%B4%D0%BD%D0%B5%D0%B9+%D1%81%D1%82%D1%80%D0%BE%D1%87%D0%BA%D0%B5%3F&sca_esv=8d0818874bd6c6ba&sxsrf=APpeQnvrQXXlUKqHHEdF9Mzz0UasQMzw3w%3A1786468654235&source=hp&ei=Lll7as2XC7Pqi-gPtOjwqQo&iflsig=ABILxe8AAAAAantnPiBkTA1x-b9fFq-zE9bvEm1kINcu&aep=22&ved=0ahUKEwjN5qOsipmWAxUz9QIHHTQ0PKUQteYPCB0&cs=1&oq=%D0%9F%D0%BE%D1%87%D0%B5%D0%BC%D1%83+%D0%B2+%D0%BA%D0%BE%D0%B4%D0%B5+%0D%0A%0D%0A++++QPainter+*painter+%3D+new+QPainter%28this%29%3B%0D%0A%0D%0A++++QLinearGradient+*gradVer+%3D+new+QLinearGradient%280%2C+20%2C+0%2C+110%29%3B%0D%0A%0D%0A++++gradVer-%3EsetColorAt%280.1%2C+Qt%3A%3Ablack%29%3B%0D%0A++++gradVer-%3EsetColorAt%280.5%2C+Qt%3A%3Ayellow%29%3B%0D%0A++++gradVer-%3EsetColorAt%280.9%2C+Qt%3A%3Ablue%29%3B%0D%0A%0D%0A++++painter-%3EfillRect%2820%2C+20%2C+1000%2C+500%2C+gradVer%29%3B%0D%0A++++%0D%0A++++%D0%BE%D1%88%D0%B8%D0%B1%D0%BA%D0%B0+%D0%B2+%D0%BF%D0%BE%D1%81%D0%BB%D0%B5%D0%B4%D0%BD%D0%B5%D0%B9+%D1%81%D1%82%D1%80%D0%BE%D1%87%D0%BA%D0%B5%3F&gs_lp=Egdnd3Mtd2l6IvYC0J_QvtGH0LXQvNGDINCyINC60L7QtNC1IAoKICAgIFFQYWludGVyICpwYWludGVyID0gbmV3IFFQYWludGVyKHRoaXMpOwoKICAgIFFMaW5lYXJHcmFkaWVudCAqZ3JhZFZlciA9IG5ldyBRTGluZWFyR3JhZGllbnQoMCwgMjAsIDAsIDExMCk7CgogICAgZ3JhZFZlci0-c2V0Q29sb3JBdCgwLjEsIFF0OjpibGFjayk7CiAgICBncmFkVmVyLT5zZXRDb2xvckF0KDAuNSwgUXQ6OnllbGxvdyk7CiAgICBncmFkVmVyLT5zZXRDb2xvckF0KDAuOSwgUXQ6OmJsdWUpOwoKICAgIHBhaW50ZXItPmZpbGxSZWN0KDIwLCAyMCwgMTAwMCwgNTAwLCBncmFkVmVyKTsKICAgIAogICAg0L7RiNC40LHQutCwINCyINC_0L7RgdC70LXQtNC90LXQuSDRgdGC0YDQvtGH0LrQtT8yEBAjGPAFGJ4GGKIHGOoCGCcyBxAjGOoCGCcyBxAjGOoCGCcyBxAjGOoCGCcyBxAjGOoCGCcyEBAjGPAFGJ4GGKIHGOoCGCcyBxAjGOoCGCcyBxAjGOoCGCcyEBAjGPAFGJ4GGKIHGOoCGCcyBxAjGOoCGCdIzrMEUO4NWMOfBHAFeACQAQCYAWigAYMKqgEEMTEuM7gBAcgBAPgBAfgBApgCE6AC8QuoAgrCAgsQABiABBixAxiDAcICDhAAGIAEGIoFGLEDGIMBwgIREC4YgAQYsQMYgwEYxwEY0QPCAggQABiABBixA8ICDRAjGKIHGJ4GGPAFGCfCAgUQABiABMICDRAjGPAFGJ4GGKIHGCfCAgQQABgDwgILEC4YgAQYsQMYgwHCAgYQABgWGB7CAgUQABjvBcICCBAAGIAEGKIEmAMI8QVeyiJozt4OTpIHBDcuMTKgB-W3AbIHBDIuMTK4B9wLwgcIMC40LjIuMTPIB7ABgAgB&sclient=gws-wiz&mstk=AUtExfAqlPMNuIIxhffmeoYQX3_203EgaA1hOYsnIn6EDkKJSeB4vGzFCLNvkzwlTUOaalKlcRscdmTz81G5yB3KYshVi6xo_vx61BDOhwnPGIlw208pii8zytouc6QdOyOduX4qfVNRohNuv3yz18-DkRN8ofKwt7Akz7JXYdA2z9B4V3HO8GkCI0LTKej7i6z5Z1lx7DSdaSAgFoz_eZdebTsEGYUy8PDGHIvWjqxIfs5FeFgGb10_hzVUP-EnwxWhUwSflhhkGeY2a2Sga8cLd5TFYjZyI8ij4vg&csuir=1&atvm=2&mtid=sl97apuoKKW0wPAPttTewQM&zx=1786470326093&udm=50
)

Чтобы заставить градиент плавно переливаться, мы добавим в класс таймер (`QTimer`). 

По сигналу этого таймера мы будем немного изменять позиции цветов градиента и принудительно обновлять виджет с помощью метода `update()`.

#### 1. Файл заголовка mywidget.h

Добавляем переменную шага анимации `m_offset` и объект таймера `m_timer`.

    #pragma once
    #ifndef MYWIDGET_H
    #define MYWIDGET_H
    
    #include <QWidget>
    #include <QLinearGradient>
    #include <QPainter>
    #include <QTimer> // Добавили таймер
    
    class MyWidget : public QWidget {
        Q_OBJECT
    
    public:
        MyWidget(QWidget *parent = nullptr);
        ~MyWidget() = default;
    
    protected:
        void paintEvent(QPaintEvent *event) override;
    
    private:
        QLinearGradient m_gradVer; 
        QTimer m_timer;          // Таймер для анимации
        double m_offset = 0.0;   // Смещение цветов (от 0.0 до 1.0)
    };
    
    #endif // MYWIDGET_H


#### 2. Файл реализации mywidget.cpp
В конструкторе мы настраиваем таймер и связываем его со специальной функцией (лямбдой), которая увеличивает смещение и заставляет виджет перерисоваться.
        
    #include "mywidget.h"
    #include <cmath>        // Обязательно для std::fmod
    
    MyWidget::MyWidget(QWidget *parent) : QWidget(parent) {
        // 1. Базовая настройка адаптивного градиента
        m_gradVer.setCoordinateMode(QGradient::ObjectMode);
        m_gradVer.setStart(0.0, 0.0);
        m_gradVer.setFinalStop(0.0, 1.0);
    
        // 2. Настраиваем таймер (30 миллисекунд ~ 33 кадра в секунду для плавности)
        connect(&m_timer, &QTimer::timeout, this, [this]() {
            m_offset += 0.01; // Скорость анимации
            if (m_offset > 1.0) {
                m_offset = 0.0; // Сбрасываем при полном цикле
            }
            this->update(); // Запрашиваем перерисовку виджета (вызов paintEvent)
        });
        
        m_timer.start(30); // Запускаем таймер
    }
    
    void MyWidget::paintEvent([[maybe_unused]] QPaintEvent *event) {
        
        QPainter painter(this);
    
        // 3. Динамически пересчитываем позиции цветов с учетом смещения m_offset.
        // Используем функцию fmod, чтобы значения позиций всегда оставались в рамках [0.0, 1.0]
        double posBlack  = std::fmod(0.1 + m_offset, 1.0);
        double posYellow = std::fmod(0.5 + m_offset, 1.0);
        double posBlue   = std::fmod(0.9 + m_offset, 1.0);
    
        m_gradVer.setColorAt(posBlack, Qt::black);
        m_gradVer.setColorAt(posYellow, Qt::yellow);
        m_gradVer.setColorAt(posBlue, Qt::blue);
    
        // 4. Отрисовка
        painter.fillRect(0, 0, this->width(), this->height(), m_gradVer);
    }

#### Как это работает:
Таймер каждые 30 мс увеличивает `m_offset` и вызывает `update()`.

Метод `update()` сообщает операционной системе, что виджет нужно обновить, и Qt вызывает `paintEvent`.

Внутри `paintEvent` позиции цветов сдвигаются вперед. Операция `std::fmod(..., 1.0)` создает эффект «зацикливания»: цвет, дошедший до самого низа (1.0), плавно появляется на самом верху (0.0).

Этот подход сохраняет процессор холодным, так как все объекты (`QPainter`, таймер, переменные) работают на стеке или управляются автоматически как поля класса.

## Почему анимация «сломалась»?

С точки зрения компиляции и вызова методов всё написано абсолютно верно, но визуально анимация действительно выглядит дёрганой, а цвета могут резко перескакивать.

Причина кроется в математике `std::fmod` и том, как Qt обрабатывает изменения позиций ключевых точек градиента.

- 1.<b>Цвета меняются местами:</b> Когда `m_offset` растет, точки сдвигаются. Например, в какой-то момент синий цвет (изначально 0.9) переваливает за 1.0, сбрасывается в 0.0 и оказывается выше черного (изначально 0.1). В этот микросекундный момент градиент пытается построить палитру «синий -> черный -> желтый -> синий». Цвета резко переворачиваются наизнанку.
- 2.<b>Эффект «зажеванной пленки»:</b> Метод `setColorAt` не заменяет цвета, он добавляет новые точки в массив градиента, если позиции различаются. Внутри `paintEvent` вы бесконечно плодите новые остановки цвета, из-за чего внутренний массив Qt переполняется, и градиент начинает мерцать или застывает.

### Как сделать перелив идеально правильным и плавным?

Вместо того чтобы двигать точки внутри отрезка [0.0, 1.0], нужно двигать сами физические координаты старта и финиша градиента на плоскости, а цвета зафиксировать раз и навсегда.

Поскольку у нас включен режим `QGradient::ObjectMode`, координаты (0, 0) и (0, 1) — это относительные верх и низ. Если мы начнем плавно смещать Y-координаты старта и финиша вниз, а режим повторения градиента переключим в цикличный (`QGradient::RepeatSpread`), мы получим бесконечную, математически чистую и плавную анимацию бегущей волны.

#### 1. Исправленный конструктор в iridescentlingrad.cpp
Убираем динамический расчет Y-координат из конструктора, фиксируем цвета один раз, и включаем режим повторения RepeatSpread.

    #include "iridescentlingrad.h"
    #include <cmath>
    
    IridescentLinGrad::IridescentLinGrad(QWidget *parent) : QWidget(parent) {
        m_gradVer.setCoordinateMode(QGradient::ObjectMode);
        
        // КРИТИЧЕСКИ ВАЖНО: заставляем Qt автоматически зацикливать градиент
        m_gradVer.setSpread(QGradient::RepeatSpread); 
    
        // Задаем цвета жестко ОДИН раз. Они больше не будут путаться местами.
        m_gradVer.setColorAt(0.0, Qt::black);
        m_gradVer.setColorAt(0.33, Qt::yellow);
        m_gradVer.setColorAt(0.66, Qt::blue);
        m_gradVer.setColorAt(1.0, Qt::black); // Замыкаем в черный, чтобы не было стыка
    
        connect(&m_timer, &QTimer::timeout, this, [this]() {
            m_offset += 0.005; // Скорость бега волны
            if (m_offset > 1.0) {
                m_offset = 0.0;
            }
            this->update(); 
        });
    
        m_timer.start(16); 
    }

#### 2. Исправленный метод paintEvent в iridescentlingrad.cpp
Теперь мы просто смещаем Y-координаты вектора градиента на величину `m_offset`. Цвета едут плавно, без переворотов.
    
    void IridescentLinGrad::paintEvent([[maybe_unused]] QPaintEvent *e) {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
    
        // Двигаем сам вектор градиента вниз по оси Y
        m_gradVer.setStart(0.0, 0.0 + m_offset);
        m_gradVer.setFinalStop(0.0, 1.0 + m_offset);
    
        // Отрисовка на все окно
        painter.fillRect(0, 0, this->width(), this->height(), m_gradVer);
    }

#### Что изменилось?

- Идеальная плавность: Цвета зафиксированы (0.0, 0.33, 0.66, 1.0), они больше никогда не поменяются местами и не вызовут визуального шока у отрисовщика Qt.

- Никаких утечек внутри Qt: Мы больше не перегружаем внутренний массив остановок градиента бесконечными вызовами setColorAt в каждом кадре.

# ẞ
