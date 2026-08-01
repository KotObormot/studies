#include <QHBoxLayout>
#include "combodoxex.h"

ComboDoxEx::ComboDoxEx(QWidget *parent) : QWidget(parent) {

    // В QStringList хранятся данные QComboBox, а именно список названий дистрибутивов Linux:
    // The QStringList stores the QComboBox data, namely a list of Linux distribution names:
    QStringList distros = {"Arch"
                           , "Xubuntu"
                           , "Redhat"
                           , "Debian"
                           , "Mandriva"};

    QHBoxLayout *hbox = new QHBoxLayout(this);

    // Создаем QComboBox, а затем с помощью метода addItems() добавляем в него элементы:
    combo = new QComboBox;
    combo->addItems(distros);

    hbox->addWidget(combo);
    hbox->addSpacing(15);

    label = new QLabel("Arch");
    hbox->addWidget(label);

    // Сигнал activated() нашего QComboBox подключается к слоту setText() метки.
    // Поскольку сигнал перегружен, то мы делаем статическое преобразование данных при помощи оператора static_cast:
    // The activated() signal of our QComboBox is connected to the setText() slot of the label.
    // Since the signal is overloaded, we perform a static data conversion using the static_cast operator:
    // connect(combo, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::activated)
    //        , label, &QLabel::setText);
    /*
     В вашем коде используется старая версия сигнала QComboBox::activated(const QString &).
    В современных версиях Qt (начиная с Qt 6) этот сигнал был удален, а вместо него остался только QComboBox::activated(int).
    Именно поэтому компилятор выдает ошибку: он не может выполнить static_cast к сигналу со строкой, так как его больше не существует в классе QComboBox.
    Если вы хотите отслеживать изменение текста по его выбору, в Qt 6 для этого появился новый сигнал: textActivated(const QString &).
    Он не перегружен, поэтому никакой static_cast вообще не нужен.
    */
    // Сигнал textActivated() отправляет выбранную строку напрямую в слот setText() метки.
    // static_cast больше не требуется, так как сигнал не перегружен.
    connect(combo, &QComboBox::textActivated, label, &QLabel::setText);
}

ComboDoxEx::~ComboDoxEx() {}
