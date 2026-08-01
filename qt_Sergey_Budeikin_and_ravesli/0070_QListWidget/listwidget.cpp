#include "listwidget.h"
#include <QVBoxLayout>
#include <QInputDialog>

ListWidget::ListWidget(QWidget *parent) : QWidget(parent) {

    QVBoxLayout *vbox = new QVBoxLayout();
    vbox->setSpacing(10);

    QHBoxLayout *hbox = new QHBoxLayout(this);

    // Создаем QListWidget и заполняем его пятью элементами:
    lw = new QListWidget(this);
    lw->addItem("The Omen");
    lw->addItem("The Exorcist");
    lw->addItem("Notes on a Scandal");
    lw->addItem("Fargo");
    lw->addItem("Capote");
    lw->addItem("Christopher Nolan's Odyssey");

    add = new QPushButton("Add", this);
    rename = new QPushButton("Rename", this);
    remove = new QPushButton("Remove", this);
    removeAll = new QPushButton("Remove all", this);

    vbox->setSpacing(3);
    vbox->addStretch(1);
    vbox->addWidget(add);
    vbox->addWidget(rename);
    vbox->addWidget(remove);
    vbox->addWidget(removeAll);
    vbox->addStretch(1);

    hbox->addWidget(lw);
    hbox->addSpacing(15);
    hbox->addLayout(vbox);

    connect(add, &QPushButton::clicked, this, &ListWidget::AddItem);
    connect(rename, &QPushButton::clicked, this, &ListWidget::renameItem);
    connect(remove, &QPushButton::clicked, this, &ListWidget::removeItem);
    connect(removeAll, &QPushButton::clicked, this, &ListWidget::clearItems);
}

ListWidget::~ListWidget() {}

void ListWidget::AddItem() {
    // Добавление нового элемента в виджет списка выполняется с помощью метода addItem():
    //     данный метод открывает диалоговое окно ввода, которое возвращает строковое значение;
    //    затем мы удаляем возможные символы пробела из строки с помощью метода simplified();
    //      метод QString::simplified() возвращает строку, в которой символы пробела удалены в начале и в конце,
    //      а все неодиночные пробелы, находящиеся внутри строки, заменены одиночными;
    //    если возвращаемая строка не пуста, то мы добавляем её в конец виджета списка;
    //    наконец, выделяем текущий добавленный элемент с помощью метода setCurrentRow().
    QString c_text = QInputDialog::getText(this, "Item", "Enter new item");
    QString s_text = c_text.simplified();

    if(!s_text.isEmpty()) {
        lw->addItem(s_text);
        int r = lw->count() - 1;
        lw->setCurrentRow(r);
    }
}

void ListWidget::renameItem() {
    // Переименование элемента состоит из нескольких шагов:
    //      сначала мы получаем текущий элемент списка и номер строки, в которой он находится, с помощью метода currentItem();
    //    текст элемента отображается в диалоговом окне QInputDialog.
    //      Строка, возвращаемая из диалогового окна, для удаления потенциальных символов пробела обрабатывается методом simplified();
    //    затем мы извлекаем старый элемент с помощью метода takeItem() и заменяем его на другой элемент с помощью метода insertItem();
    //    затем удаляем элемент, извлеченный методом takeItem() (поскольку извлеченные элементы больше не управляются Qt, то это нужно сделать «ручками»);
    //    наконец, при помощи метода setCurrentRow(), устанавливаем новый текущий элемент.
    QListWidgetItem *currItem = lw->currentItem();

    int r = lw->row(currItem);
    QString c_text = currItem->text();
    QString r_text = QInputDialog::getText(this, "Item", "Enter new item", QLineEdit::Normal, c_text);

    QString s_text = r_text.simplified();

    if(!s_text.isEmpty()) {
        QListWidgetItem *item = lw->takeItem(r);
        delete item;
        lw->insertItem(r, s_text);
        lw->setCurrentRow(r);
    }
}

void ListWidget::removeItem() {
    // Удаление определенного элемента из списка осуществляется с помощью метода removeItem().
    // Сначала мы получаем текущую строку с помощью метода currentRow() (он возвращает -1, если строк больше не осталось),
    // затем текущий выбранный элемент извлекается с помощью метода takeItem():
    int r = lw->currentRow();
    if(r != -1) {
        QListWidgetItem *item = lw->takeItem(r);
        delete item;
    }
}

void ListWidget::clearItems() {
    // метод clear() удаляет все элементы из виджета списка:
    if(lw->count() != 0) {
        lw->clear();
    }
}
