#include <QPainter>
#include <QTime>
#include "snake.h"

Snake::Snake(QWidget *parent)
    : QWidget(parent)
{
    setStyleSheet("background-color:black");
    leftDirection = false;
    rightDirection = true;
    upDirection = false;
    downDirection = false;
    inGame = true;

    resize(B_WIDTH, B_HEIGHT);
    loadImages();
    initGame();
}

//Snake::~Snake() {}

void Snake::loadImages()
{
    dot.load("://images/dot.png");
    head.load("://images/head.png");
    apple.load("://images/apple.png");
}

void Snake::initGame()
{
    dots = 3;

    for(int z = 0; z < dots; z++) {
        x[z] = 50 - z * 10;
        y[z] = 50;
    }

    locateApple();

    timerID = startTimer(DELAY);
}


void Snake::paintEvent([[maybe_unused]] QPaintEvent *e)
{
    doDrawing();
}

void Snake::doDrawing()
{
    QPainter qp(this);

    if(inGame) {
        qp.drawImage(apple_x, apple_y, apple);

        for(int z = 0; z < dots; z++) {
            if(z == 0) {
                qp.drawImage(x[z], y[z], head);
            } else {
                qp.drawImage(x[z], y[z], dot);
            }
        }
    } else {
        gameOver(qp);
    }
}
