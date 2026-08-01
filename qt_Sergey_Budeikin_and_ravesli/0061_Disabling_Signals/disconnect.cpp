#include "disconnect.h"
#include <QTextStream>
#include <QCheckBox>
#include <QHBoxLayout>

Disconnect::Disconnect(QWidget *parent) : QWidget(parent) {

    QHBoxLayout *hbox = new QHBoxLayout(this);
    hbox->setSpacing(5);

    clickBtn = new QPushButton("Click", this);
    hbox->addWidget(clickBtn, 0, Qt::AlignLeft | Qt::AlignTop);

    QCheckBox *cb = new QCheckBox("Connect", this);
    cb->setCheckState(Qt::Checked);
    hbox->addWidget(cb, 0, Qt::AlignLeft | Qt::AlignTop);

    // Подключаем сигналы к нашим пользовательским слотам:
    connect(clickBtn, &QPushButton::clicked, this, &Disconnect::onClick);
    //connect(cb, &QCheckBox::stateChanged, this, &Disconnect::onCheck);  // disconnect.cpp:20:29: 'stateChanged' is deprecated: Use checkStateChanged() instead
                                                                        //:40:19: note: 'stateChanged' has been explicitly marked deprecated here
    connect(cb, &QCheckBox::checkStateChanged, this, &Disconnect::onCheck);
}

// Если мы делаем щелчок мышкой, то в окно терминала будет отправляться текст Button clicked:
void Disconnect::onClick() {
    QTextStream out(stdout);
    out << "Button clicked" << Qt::endl;
}

// Внутри слота onCheck() мы подключаем или отключаем слот onClick() от кнопки, в зависимости от полученного параметра состояния:
// Мне надо переписать слот
//void Disconnect::onCheck(int state) {
//    if(state == Qt::Checked) {
//        connect(clickBtn, &QPushButton::clicked, this, &Disconnect::onClick);
//    } else {
//        disconnect(clickBtn, &QPushButton::clicked, this, &Disconnect::onClick);
//    }
//}

void Disconnect::onCheck(Qt::CheckState state) {
    if(state == Qt::CheckState::Checked) {
        connect(clickBtn, &QPushButton::clicked, this, &Disconnect::onClick);
    } else if(state == Qt::CheckState::Unchecked) {
        disconnect(clickBtn, &QPushButton::clicked, this, &Disconnect::onClick);
    }
}

Disconnect::~Disconnect() {}
