#pragma once

#ifndef SPLITTER_H
#define SPLITTER_H

#include <QWidget>

class Splitter : public QWidget {
    Q_OBJECT

  public:
    Splitter(QWidget *parent = nullptr);
    ~Splitter();
};
#endif // SPLITTER_H
