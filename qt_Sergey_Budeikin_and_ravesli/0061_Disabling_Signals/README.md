2026-07-04 0061 Отключение сигналов / 0061 Disabling signals

https://www.youtube.com/watch?v=o488uV3-RLk&list=PL0-ON4z3RPUO-BMP4L-9UvG2ADmMWhW24

154 просмотра  5 нояб. 2021 г.  Qt Начало
В данном видео уроке мы с вами разберём такую тему как с помощью кода включать и отключать сигналы. / 
154 views November 5, 2021 Qt Start
In this video tutorial, we'll cover how to enable and disable signals using code.

See also https://ravesli.com/urok-9-sloty-signaly-i-sobytiya-v-qt5/#toc-4

Отключение сигналов

Сигнал может быть отключен от слота. Следующий пример показывает, как это можно сделать.

В заголовочном файле мы объявили два слота. Следует отметить, что slot не является ключевым словом в языке C++, а лишь расширением Qt5. Подобные расширения обрабатываются препроцессором фреймворка до выполнения компиляции кода. Когда в наших классах мы используем сигналы и слоты, то обязательно должны предоставить макрос Q_OBJECT в начале определения класса. В противном случае препроцессор будет выдавать сообщения об ошибках.

В следующем примере у нас есть кнопка и флажок. Флажок подключает и отключает слот от сигнала нажатия кнопок.

/ 

Disabling Signals

A signal can be disconnected from a slot. The following example shows how this can be done.

In the header file, we declared two slots. It's worth noting that "slot" is not a keyword in C++, but rather a Qt5 extension. Such extensions are processed by the framework's preprocessor before compiling the code. When using signals and slots in our classes, we must provide the Q_OBJECT macro at the beginning of the class definition. Otherwise, the preprocessor will generate error messages.

In the following example, we have a button and a checkbox. The checkbox connects and disconnects the slot from the button's click signal.

==============================================================================

Cигнал &QCheckBox::stateChanged в библиотеке Qt признан устаревшим (deprecated) 
и будет полностью удален в будущих версиях.

Разработчики Qt советуют отказаться от него в пользу нового, более безопасного сигнала.

Почему его признали устаревшим?

Старый сигнал stateChanged(int state) передавал состояние чекбокса в виде обычного числа int. Это заставляло разработчиков вручную приводить типы или использовать числа, что ухудшало читаемость кода и могло приводить к ошибкам.

На что его заменить?

Взамен старого сигнала в Qt добавили сигнал checkStateChanged(Qt::CheckState state), который сразу передает строго типизированное состояние.

Как исправить код?

Вам нужно обновить синтаксис подключения сигнала в функции connect.

Было (устаревший вариант):

connect(ui->checkBox, &QCheckBox::stateChanged, this, &MainWindow::onStateChanged);

// И в самом слоте:
void MainWindow::onStateChanged(int state) {
    if (state == Qt::Checked) { /* ... */ }
}


// И в самом слоте:
void MainWindow::onStateChanged(int state) {
    if (state == Qt::Checked) { /* ... */ }
}


Стало (современный вариант):

connect(ui->checkBox, &QCheckBox::checkStateChanged, this, &MainWindow::onCheckStateChanged);

// И в самом слоте:

void MainWindow::onCheckStateChanged(Qt::CheckState state) {
    if (state == Qt::Checked) { /* ... */ }
}


Альтернативный вариант

Если вам нужно просто знать, нажат флажок или нет (true/false) без учета промежуточного состояния (например, когда чекбокс частично закрашен), можно использовать сигнал toggled(bool):

connect(ui->checkBox, &QCheckBox::toggled, this, &MainWindow::onToggled);

На что обратить внимание:

Тип данных: 

Вместо int state теперь используется строго типизированное перечисление Qt::CheckState state.

Безопасность: 

Если ваш чекбокс поддерживает третье (частично отмеченное) состояние Qt::PartiallyChecked, конструкция else if гарантирует, что отключение произойдет только при полном снятии флажка.

=================================================================================

The &QCheckBox::stateChanged signal has been deprecated in the Qt library
and will be completely removed in future versions.

The Qt developers recommend deprecating it in favor of a new, safer signal.

Why was it deprecated?

The old stateChanged(int state) signal communicated the checkbox state as a regular int. This forced developers to manually cast types or use numbers, which made code less readable and could lead to errors.

What should it be replaced with?

To replace the old signal, Qt now has a new signal, checkStateChanged(Qt::CheckState state), which immediately returns a strongly typed state.

How do I fix the code?

You need to update the signal connection syntax in the connect function.

Previous (deprecated):

connect(ui->checkBox, &QCheckBox::stateChanged, this, &MainWindow::onStateChanged);

// And in the slot itself:
void MainWindow::onStateChanged(int state) {
if (state == Qt::Checked) { /* ... */ }
}

// And in the slot itself:
void MainWindow::onStateChanged(int state) {
if (state == Qt::Checked) { /* ... */ }
}

Now (modern version):

connect(ui->checkBox, &QCheckBox::checkStateChanged, this, &MainWindow::onCheckStateChanged);

// And in the slot itself:

void MainWindow::onCheckStateChanged(Qt::CheckState state) {
if (state == Qt::Checked) { /* ... */ }
}

Alternative Option

If you simply need to know whether the checkbox is checked or not (true/false) without taking into account any intermediate state (for example, when the checkbox is partially filled), you can use the toggled(bool) signal:

connect(ui->checkBox, &QCheckBox::toggled, this, &MainWindow::onToggled);

Note:

Data Type:

Instead of int state, the strongly typed enum Qt::CheckState state is now used.

Safety:

If your checkbox supports a third (partially checked) state, Qt::PartiallyChecked, the else if statement ensures that the checkbox is only disabled when the checkbox is completely unchecked.
