#pragma once

#ifndef VERTICALBOX_H
#define VERTICALBOX_H

#include <QWidget>
//#include <QApplication>

class VerticalBox : public QWidget {
    Q_OBJECT

public:
    VerticalBox(QWidget *parent = nullptr);
    ~VerticalBox();
};
#endif // VERTICALBOX_H
