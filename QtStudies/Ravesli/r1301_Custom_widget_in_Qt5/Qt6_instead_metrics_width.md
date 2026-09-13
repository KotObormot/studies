# что вместо int w = metrics.width(

В современных версиях Qt (начиная с Qt 5.11 и в Qt 6) старый метод `QFontMetrics::width()` был объявлен устаревшим (deprecated), а затем удален, так как он не учитывал дробное позиционирование символов и возвращал неточные целые значения.

Вместо него теперь нужно использовать метод `horizontalAdvance()`.

Вот как правильно переписать вашу строку:

    int w = metrics.horizontalAdvance(num[i - 1]);

## Дополнительные варианты (в зависимости от типа данных)
Если `num[i - 1]` — это:

* `QString` или `QChar`: используйте `metrics.horizontalAdvance(...)`.
* Дробная точность: если вам нужна максимальная точность для верстки (особенно на High-DPI экранах), используйте `QFontMetricsF` вместо `QFontMetrics` и метод `horizontalAdvance()`, который вернет `qreal (double)`:

    `qreal w = metrics.horizontalAdvance(num[i - 1]);`


- [AI](https://share.google/aimode/2GsinOexEpPKRXSOF)

# ẞ
