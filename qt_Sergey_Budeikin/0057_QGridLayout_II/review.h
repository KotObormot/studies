#pragma once

#ifndef REVIEW_H
#define REVIEW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Review;
}
QT_END_NAMESPACE

class Review : public QWidget {
    Q_OBJECT

  public:
    Review(QWidget *parent = nullptr);
    ~Review();

  private:
    Ui::Review *ui;
};
#endif // REVIEW_H
