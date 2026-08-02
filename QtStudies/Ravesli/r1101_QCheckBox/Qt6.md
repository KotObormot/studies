# Замена QCheckBox::stateChanged в Qt6

Чем в Qt6 заменить stateChanged в connect(chB, \&QCheckBox::stateChanged, this, \&CheckBox::showTitle);


https://www.google.com/search?udm=50\&mstk=AUtExfAU4pA7hjuHbdHnuiN9pmUAB6CNARaI-\_QCnzPKjfPKl0mpG0PtaSD-9guDDY247MAMdaDCWu\_4gDIH5FP4htQzONOST2NTg\_CHxsPgrRoHG-OYdqHmWKuBGGo3wLYXPy-mfOztm9pJJDn0eWMSS8HBHM\_95Lwyn32roPW6MWwVYXYCjiBiVM4XQ32L1MSNXLDoGj4k8BIKwrE3mggnS6bUrkXr9vFCdfAGJKKp-2CCDwnkbAFuCHww2xgmAXO-aIcqRrrz7h00VQ\&csuir=1\&q=%D1%87%D0%B5%D0%BC+%D0%B2+Qt6+%D0%B7%D0%B0%D0%BC%D0%B5%D0%BD%D0%B8%D1%82%D1%8C+stateChanged+%D0%B2++connect%28chB%2C+%26QCheckBox%3A%3AstateChanged%2C+this%2C+%26CheckBox%3A%3AshowTitle%29%3B\&aep=146\&atvm=2\&mtid=SMRjas7JN4Wj3QOuyKzRBQ

В **Qt 6** сигнал QCheckBox::stateChanged стал устаревшим (deprecated), так как он передавал целочисленное значение int (состояния Qt::CheckState).

Вместо него для отслеживания изменения состояния чекбокса теперь нужно использовать сигнал **checkStateChanged**.

Вот как правильно переписать ваше подключение:

    connect(chB, &QCheckBox::checkStateChanged, this, &CheckBox::showTitle);

## **Важные нюансы перевода на Qt 6:**

> * **Новый тип данных**: Сигнал checkStateChanged передает перечисление Qt::CheckState вместо int.  
> * **Изменение сигнатуры слота**: Если ваш слот showTitle принимал int, измените его аргумент на Qt::CheckState (например, void showTitle(Qt::CheckState state)).  
> * **Альтернатива для двух состояний**: Если вам нужно знать только нажат чекбокс или нет (без учета третьего частично нажатого состояния Qt::PartiallyChecked), лучше использовать сигнал toggled:  

    connect(chB, &QCheckBox::toggled, this, &CheckBox::showTitle);   // В этом случае слот должен принимать bool: void showTitle(bool checked);`*

Если вы хотите оптимизировать и другие части кода под актуальную версию фреймворка, укажите:

> * Использует ли ваш чекбокс **третье состояние** (tristate)?  
> * Какую **сигнатуру** имеет ваш слот showTitle сейчас?

Я помогу настроить подключение и логику слота под стандарты Qt 6\.

Вот обновленный вариант слота и его подключения, полностью совместимый с **Qt 6**.

Так как вы проверяете только два состояния (`Qt::Checked` или его отсутствие), проще и чище всего перевести код на сигнал `toggled` и логический тип `bool`.

## Вариант 1: Через `toggled` (Рекомендуемый)

Этот способ избавляет от лишних перечислений, если вам не нужно третье (частично замаскированное) состояние чекбокса.

**Объявление в заголовочном файле (`.h`):**

void showTitle(bool checked);

**Реализация слота (`.cpp`):**

void CheckBox::showTitle(bool checked) {

    if (checked) {

        setWindowTitle("QCheckbox");

    } else {

        setWindowTitle(" ");

    }

}

**Подключение (`connect`):**

    connect(chB, &QCheckBox::toggled, this, \&CheckBox::showTitle);

---

## Вариант 2: Через `checkStateChanged` (Если важно перечисление)

Используйте этот вариант, если проект в будущем будет поддерживать три состояния чекбокса (tristate).

**Объявление в заголовочном файле (`.h`):**

    void showTitle(Qt::CheckState state);

**Реализация слота (`.cpp`):**

    void CheckBox::showTitle(Qt::CheckState state) {
    
        if (state == Qt::Checked) {
    
            setWindowTitle("QCheckbox");
    
        } else {
    
            setWindowTitle(" ");
    
        }
    
    }

**Подключение (`connect`):**

    connect(chB, &QCheckBox::checkStateChanged, this, &CheckBox::showTitle);

Чтобы сделать код еще компактнее, условие `if-else` в обоих вариантах можно заменить на тернарный оператор:

    setWindowTitle(checked ? "QCheckbox" : " ");

Если вы хотите продолжить обновление проекта, сообщите:

* Встречаются ли в коде другие **устаревшие методы** (например, от `QAction` или `QList`)?  
* Используете ли вы **лямбда-выражения** в `connect`?

Я помогу адаптировать оставшиеся части кода под стандарты Qt 6\.

### А откуда в тернарном операторе берется checked ?

Переменная `checked` берется из **аргумента самого слота**, если вы выбрали **Вариант 1** (через сигнал `toggled`).

Когда пользователь нажимает на чекбокс, сигнал `QCheckBox::toggled(bool checked)` автоматически передает текущее состояние (включен или выключен) в ваш слот в виде переменной `checked`.

Вот как это выглядит внутри обновленного слота:

    void CheckBox::showTitle(bool checked) {
    
        // checked — это имя переменной, которую мы получили на входе в слот
    
        setWindowTitle(checked ? "QCheckbox" : " ");
    
    }

Если же вы используете **Вариант 2** (через `checkStateChanged`), то переменная на входе будет называться `state`, и тернарный оператор запишется так:

    void CheckBox::showTitle(Qt::CheckState state) {
    
        setWindowTitle(state == Qt::Checked ? "QCheckbox" : " ");
    
    }

Если вы хотите сделать код еще современнее, его можно написать вообще без создания отдельного слота в `.h` файле — с помощью **лямбда-выражения** прямо в `connect`.

Хотите посмотреть, как переписать это подключение в **одну строку через лямбду**, чтобы не плодить лишние функции?

Переход на новые сигналы в Qt 6 делает код безопаснее, так как компилятор теперь сразу проверяет строгое соответствие типов (bool или Qt::CheckState) вместо работы с обычными числами int.

Когда будете готовы продолжить или если в процессе компиляции возникнут вопросы по типам данных, просто дайте знать.

Если захотите, позже мы сможем:

* Разобрать **лямбда-функции** для сокращения кода `connect`.  
* Посмотреть другие **изменения в Qt 6**, которые могут затронуть ваш проект.  
* Оптимизировать работу с **другими виджетами** (кнопками, списками или меню).

Удачи в осмыслении и успешной компиляции\! Напишите, когда будете готовы двигаться дальше.

# ẞ
