#pragma once

#ifndef DISCONNECT_H
#define DISCONNECT_H

#include <QWidget>
#include <QPushButton>

class Disconnect : public QWidget {
    Q_OBJECT

  public:
    Disconnect(QWidget *parent = nullptr);
    ~Disconnect();

  private slots:
    void onClick();
    //void onCheck(int);
    void onCheck(Qt::CheckState);

  private:
    QPushButton *clickBtn;
};

#endif // DISCONNECT_H
