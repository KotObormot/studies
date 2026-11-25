# В Qt 6 функция qsrand() (как и qrand()) полностью удалена. 

- [AI](https://share.google/aimode/3JpvxsKbiXiFpwBJw)

Вместо них используется класс QRandomGenerator, который не требует ручной инициализации (seeding) системным временем.

## Как заменить в коде

### 1. Если нужна просто случайная генерация (рекомендуемый способ):

Ничего инициализировать вообще не нужно. Глобальный генератор `QRandomGenerator::global()` уже безопасно инициализируется операционной системой при запуске.

Вместо старого кода:
    
    // Qt 5 (устарело)
    qsrand((uint) time.msec());
    int value = qrand() % 100;

Используйте:

    // Qt 6
    #include <QRandomGenerator>
    // Генерация числа от 0 до 99 включительно
    int value = QRandomGenerator::global()->bounded(100);

### 2. Если вам всё же нужен собственный генератор с конкретным зерном (`seed`):

Например, для воспроизводимости результатов в тестах или генерации уровней:

    #include <QRandomGenerator>
    #include <QTime>
    // Создаем локальный экземпляр с нужным зерном
    QRandomGenerator generator(static_cast<quint32>(QTime::currentTime().msec()));
    int value = generator.bounded(100);
- (*Примечание*: вызов `generator.seed(...)` также доступен, если объект уже создан). 


- **Основные** методы QRandomGenerator

    + `bounded(max)` — возвращает случайное число от 0 до max - 1.
    
    + `bounded(min, max)` — возвращает число в диапазоне от `min` до `max - 1` (избавляет от необходимости писать 'min + qrand() % (max - min)').

    + `generate()` — возвращает случайное беззнаковое 32-битное число (`quint32`).

    + `generateDouble()` — возвращает случайное число с плавающей точкой (`double`) в диапазоне `[0.0, 1.0)`.

#  ẞ
