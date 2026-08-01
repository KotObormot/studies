#pragma once

#ifndef SKELETON_H
#define SKELETON_H

#include <QMainWindow>
#include <QApplication>

class Skeleton : public QMainWindow {
    Q_OBJECT

public:
    Skeleton(QWidget *parent = nullptr);
    ~Skeleton();
};
#endif // SKELETON_H
