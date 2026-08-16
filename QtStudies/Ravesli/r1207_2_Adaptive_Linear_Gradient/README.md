# Kак сделать градиент динамическим и адаптивным к размеру окна?

- [AI](https://www.google.com/search?q=%D0%9F%D0%BE%D1%87%D0%B5%D0%BC%D1%83+%D0%B2+%D0%BA%D0%BE%D0%B4%D0%B5+%0D%0A%0D%0A++++QPainter+*painter+%3D+new+QPainter%28this%29%3B%0D%0A%0D%0A++++QLinearGradient+*gradVer+%3D+new+QLinearGradient%280%2C+20%2C+0%2C+110%29%3B%0D%0A%0D%0A++++gradVer-%3EsetColorAt%280.1%2C+Qt%3A%3Ablack%29%3B%0D%0A++++gradVer-%3EsetColorAt%280.5%2C+Qt%3A%3Ayellow%29%3B%0D%0A++++gradVer-%3EsetColorAt%280.9%2C+Qt%3A%3Ablue%29%3B%0D%0A%0D%0A++++painter-%3EfillRect%2820%2C+20%2C+1000%2C+500%2C+gradVer%29%3B%0D%0A++++%0D%0A++++%D0%BE%D1%88%D0%B8%D0%B1%D0%BA%D0%B0+%D0%B2+%D0%BF%D0%BE%D1%81%D0%BB%D0%B5%D0%B4%D0%BD%D0%B5%D0%B9+%D1%81%D1%82%D1%80%D0%BE%D1%87%D0%BA%D0%B5%3F&sca_esv=8d0818874bd6c6ba&sxsrf=APpeQnvrQXXlUKqHHEdF9Mzz0UasQMzw3w%3A1786468654235&source=hp&ei=Lll7as2XC7Pqi-gPtOjwqQo&iflsig=ABILxe8AAAAAantnPiBkTA1x-b9fFq-zE9bvEm1kINcu&aep=22&ved=0ahUKEwjN5qOsipmWAxUz9QIHHTQ0PKUQteYPCB0&cs=1&oq=%D0%9F%D0%BE%D1%87%D0%B5%D0%BC%D1%83+%D0%B2+%D0%BA%D0%BE%D0%B4%D0%B5+%0D%0A%0D%0A++++QPainter+*painter+%3D+new+QPainter%28this%29%3B%0D%0A%0D%0A++++QLinearGradient+*gradVer+%3D+new+QLinearGradient%280%2C+20%2C+0%2C+110%29%3B%0D%0A%0D%0A++++gradVer-%3EsetColorAt%280.1%2C+Qt%3A%3Ablack%29%3B%0D%0A++++gradVer-%3EsetColorAt%280.5%2C+Qt%3A%3Ayellow%29%3B%0D%0A++++gradVer-%3EsetColorAt%280.9%2C+Qt%3A%3Ablue%29%3B%0D%0A%0D%0A++++painter-%3EfillRect%2820%2C+20%2C+1000%2C+500%2C+gradVer%29%3B%0D%0A++++%0D%0A++++%D0%BE%D1%88%D0%B8%D0%B1%D0%BA%D0%B0+%D0%B2+%D0%BF%D0%BE%D1%81%D0%BB%D0%B5%D0%B4%D0%BD%D0%B5%D0%B9+%D1%81%D1%82%D1%80%D0%BE%D1%87%D0%BA%D0%B5%3F&gs_lp=Egdnd3Mtd2l6IvYC0J_QvtGH0LXQvNGDINCyINC60L7QtNC1IAoKICAgIFFQYWludGVyICpwYWludGVyID0gbmV3IFFQYWludGVyKHRoaXMpOwoKICAgIFFMaW5lYXJHcmFkaWVudCAqZ3JhZFZlciA9IG5ldyBRTGluZWFyR3JhZGllbnQoMCwgMjAsIDAsIDExMCk7CgogICAgZ3JhZFZlci0-c2V0Q29sb3JBdCgwLjEsIFF0OjpibGFjayk7CiAgICBncmFkVmVyLT5zZXRDb2xvckF0KDAuNSwgUXQ6OnllbGxvdyk7CiAgICBncmFkVmVyLT5zZXRDb2xvckF0KDAuOSwgUXQ6OmJsdWUpOwoKICAgIHBhaW50ZXItPmZpbGxSZWN0KDIwLCAyMCwgMTAwMCwgNTAwLCBncmFkVmVyKTsKICAgIAogICAg0L7RiNC40LHQutCwINCyINC_0L7RgdC70LXQtNC90LXQuSDRgdGC0YDQvtGH0LrQtT8yEBAjGPAFGJ4GGKIHGOoCGCcyBxAjGOoCGCcyBxAjGOoCGCcyBxAjGOoCGCcyBxAjGOoCGCcyEBAjGPAFGJ4GGKIHGOoCGCcyBxAjGOoCGCcyBxAjGOoCGCcyEBAjGPAFGJ4GGKIHGOoCGCcyBxAjGOoCGCdIzrMEUO4NWMOfBHAFeACQAQCYAWigAYMKqgEEMTEuM7gBAcgBAPgBAfgBApgCE6AC8QuoAgrCAgsQABiABBixAxiDAcICDhAAGIAEGIoFGLEDGIMBwgIREC4YgAQYsQMYgwEYxwEY0QPCAggQABiABBixA8ICDRAjGKIHGJ4GGPAFGCfCAgUQABiABMICDRAjGPAFGJ4GGKIHGCfCAgQQABgDwgILEC4YgAQYsQMYgwHCAgYQABgWGB7CAgUQABjvBcICCBAAGIAEGKIEmAMI8QVeyiJozt4OTpIHBDcuMTKgB-W3AbIHBDIuMTK4B9wLwgcIMC40LjIuMTPIB7ABgAgB&sclient=gws-wiz&mstk=AUtExfAqlPMNuIIxhffmeoYQX3_203EgaA1hOYsnIn6EDkKJSeB4vGzFCLNvkzwlTUOaalKlcRscdmTz81G5yB3KYshVi6xo_vx61BDOhwnPGIlw208pii8zytouc6QdOyOduX4qfVNRohNuv3yz18-DkRN8ofKwt7Akz7JXYdA2z9B4V3HO8GkCI0LTKej7i6z5Z1lx7DSdaSAgFoz_eZdebTsEGYUy8PDGHIvWjqxIfs5FeFgGb10_hzVUP-EnwxWhUwSflhhkGeY2a2Sga8cLd5TFYjZyI8ij4vg&csuir=1&atvm=2&mtid=sl97apuoKKW0wPAPttTewQM&zx=1786470326093&udm=50
)


Чтобы градиент автоматически подстраивался под меняющийся размер окна, нам нужно использовать относительные (логические) координаты вместо жестко заданных пикселей.

В Qt для этого у градиента переключается режим координат с помощью метода setCoordinateMode.

#### Шаг 1. Переводим градиент в режим ObjectMode

В конструкторе вместо пикселей мы указываем координаты от 0.0 (начало объекта) до 1.0 (конец объекта).

    MyWidget::MyWidget(QWidget *parent) : QWidget(parent) {
        // Переводим градиент в режим относительных координат объекта
        m_gradVer.setCoordinateMode(QGradient::ObjectMode);
        
        // Теперь (0, 0) — это левый верхний угол прямоугольника, а (0, 1) — левый нижний.
        // Градиент пойдет строго сверху вниз по всей высоте закрашиваемой области.
        m_gradVer.setStart(0.0, 0.0);
        m_gradVer.setFinalStop(0.0, 1.0);
        
        // Цвета остаются прежними
        m_gradVer.setColorAt(0.1, Qt::black);
        m_gradVer.setColorAt(0.5, Qt::yellow);
        m_gradVer.setColorAt(0.9, Qt::blue);
    }

#### Шаг 2. Привязываем размер прямоугольника к размеру виджета

В методе `paintEvent` вместо фиксированных 1000 и 500 пикселей мы используем функции `this->width()` и `this->height()`.

    painter.fillRect(0, 0, this->width(), this->height(), m_gradVer);

## Что изменилось?
- Полная адаптивность: Теперь, как бы пользователь ни растягивал окно мышкой, цвета всегда будут плавно распределяться от самого верха до самого низа.

- Производительность не упала: Расчет координат (0.0, 1.0) по-прежнему сделан один раз в конструкторе. Пересчет пикселей под новый размер окна Qt берет на себя на аппаратном уровне.

# ẞ
