# Qt6

В Qt 6 сигнал QCheckBox::stateChanged стал устаревшим (deprecated), так как он передавал целочисленное значение int (состояния Qt::CheckState).
Вместо него для отслеживания изменения состояния чекбокса теперь нужно использовать сигнал checkStateChanged.
Вот как правильно переписать ваше подключение:

    connect(chB, &QCheckBox::checkStateChanged, this, &CheckBox::showTitle);

## Важные нюансы перевода на Qt 6:

* Новый тип данных: Сигнал checkStateChanged передает перечисление Qt::CheckState вместо int.
* Изменение сигнатуры слота: Если ваш слот showTitle принимал int, измените его аргумент на Qt::CheckState (например, void showTitle(Qt::CheckState state)).
* Альтернатива для двух состояний: Если вам нужно знать только нажат чекбокс или нет (без учета третьего частично нажатого состояния Qt::PartiallyChecked), лучше использовать сигнал toggled:


        connect(chB, &QCheckBox::toggled, this, &CheckBox::showTitle); 
    // В этом случае слот должен принимать bool: void showTitle(bool checked);

---

Вот обновленный вариант слота и его подключения, полностью совместимый с Qt 6.
Так как вы проверяете только два состояния (Qt::Checked или его отсутствие), проще и чище всего перевести код на сигнал toggled и логический тип bool.
## Вариант 1: Через toggled (Рекомендуемый)
Этот способ избавляет от лишних перечислений, если вам не нужно третье (частично замаскированное) состояние чекбокса.
Объявление в заголовочном файле (.h):

    void showTitle(bool checked);

Реализация слота (.cpp):

    void CheckBox::showTitle(bool checked) {
        if (checked) {
            setWindowTitle("QCheckbox");
        } else {
            setWindowTitle(" ");
        }
}

Подключение (connect):

    connect(chB, &QCheckBox::toggled, this, &CheckBox::showTitle);

------------------------------
## Вариант 2: Через checkStateChanged (Если важно перечисление)
Используйте этот вариант, если проект в будущем будет поддерживать три состояния чекбокса (tristate).
Объявление в заголовочном файле (.h):

    void showTitle(Qt::CheckState state);

Реализация слота (.cpp):

    void CheckBox::showTitle(Qt::CheckState state) {
        if (state == Qt::Checked) {
            setWindowTitle("QCheckbox");
        } else {
            setWindowTitle(" ");
        }
    }

Подключение (connect):

    connect(chB, &QCheckBox::checkStateChanged, this, &CheckBox::showTitle);

### Чтобы сделать код еще компактнее, условие if-else в обоих вариантах можно заменить на тернарный оператор:
 
#### Вариант 1 (через сигнал toggled).
Когда пользователь нажимает на чекбокс, сигнал QCheckBox::toggled(bool checked) автоматически передает текущее состояние (включен или выключен) в ваш слот в виде переменной checked.
Вот как это выглядит внутри обновленного слота:

    void CheckBox::showTitle(bool checked) {
        // checked — это имя переменной, которую мы получили на входе в слот
        setWindowTitle(checked ? "QCheckbox" : " ");
    }

#### Если же вы используете Вариант 2 (через checkStateChanged), то переменная на входе будет называться state, и тернарный оператор запишется так:

    void CheckBox::showTitle(Qt::CheckState state) {
        setWindowTitle(state == Qt::Checked ? "QCheckbox" : " ");
    }


---
Если вы хотите сделать код еще современнее, его можно написать вообще без создания отдельного слота в .h файле — с помощью лямбда-выражения прямо в connect.

# ẞ
