#pragma once

#ifndef PIXMAP_H
#define PIXMAP_H

#include <QWidget>

class Pixmap : public QWidget {
    Q_OBJECT

  public:
    Pixmap(QWidget *parent = nullptr);
    ~Pixmap();
};
#endif // PIXMAP_H
