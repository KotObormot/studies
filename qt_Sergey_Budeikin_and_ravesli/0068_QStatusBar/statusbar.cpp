#include "statusbar.h"

StatusBar::StatusBar(QWidget *parent) : QMainWindow(parent) {

    QFrame *frame = new QFrame(this);
    setCentralWidget(frame);

    QHBoxLayout *hbox = new QHBoxLayout(frame);

    okBttn = new QPushButton("OK", frame);
    hbox->addWidget(okBttn, 0, Qt::AlignLeft | Qt::AlignTop);

    applyBttn = new QPushButton("APPLY", frame);
    hbox->addWidget(applyBttn, 0, Qt::AlignLeft | Qt::AlignTop);

    statusBar();

    connect(okBttn, &QPushButton::clicked, this, &StatusBar::OnOkPressed);
    connect(applyBttn, &QPushButton::clicked, this, &StatusBar::OnAplayPressed);
}

StatusBar::~StatusBar() {}

void StatusBar::OnOkPressed() {
    statusBar()->showMessage("OK Button Pressed", 5000);
}

void StatusBar::OnAplayPressed() {
    statusBar()->showMessage("Apply Button Pressed", 2000);
}
