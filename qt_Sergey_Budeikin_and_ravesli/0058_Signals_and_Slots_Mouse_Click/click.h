#pragma once

#ifndef CLICK_H
#define CLICK_H

#include <QWidget>

class Click : public QWidget {
    Q_OBJECT

  public:
    Click(QWidget *parent = nullptr);
    ~Click();
};
#endif // CLICK_H
