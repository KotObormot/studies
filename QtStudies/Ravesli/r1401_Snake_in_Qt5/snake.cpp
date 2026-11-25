#include <QPainter>
#include <QRandomGenerator>
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
/*При помощи метода loadImages() мы загружаем изображения, которые будут использоваться в игре. Класс QImage используется для хранения данных PNG-изображений:*/
{
    dot.load("://images/dot.png");
    head.load("://images/head.png");
    apple.load("://images/apple.png");
}

void Snake::initGame()
/*В методе initGame() мы создаем змею, случайным образом определяем позицию на игровом поле, где будет располагаться яблоко, и запускаем таймер:*/
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

void Snake::gameOver(QPainter &qp)
{
    QString message = "Game over";
    QFont font("Corier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    //int textWidth = fm.width(message);
    int textWidth = fm.horizontalAdvance(message); // вместо width в QFontMetrics in Qt6

    qp.setPen(QColor(Qt::white));
    qp.setFont(font);
    int h = height();
    int w = width();

    qp.translate(QPoint(w/2, h/2));
    qp.drawText(-textWidth/2, 0, message);
}

void Snake::checkApple()
/*Если голова сталкивается с яблоком, то мы увеличиваем количество «частей» тела змеи. Затем вызываем метод locateApple(), который случайным образом позиционирует новое яблоко:*/
{
    if((x[0] == apple_x) && (y[0] == apple_y)) {
        dots++;
        locateApple();
    }
}

void Snake::move()
/*ключевой алгоритм игры. Чтобы понять его, посмотрите, как движется змея. Мы контролируем только голову змеи.
 * При этом мы можем изменить её направление движения с помощью стрелочек.
 * Остальные «части» тела змеи по цепочке перемещаются друг за другом.
 * Вторая «часть» движется туда, где была первая, третья — туда, где была вторая и т.д.:*/
{
    for(int z = dots; z > 0; z--) {         // Перемещаем «части» тела змеи друг за другом:
        x[z] = x[(z - 1)];
        y[z] = y[(z - 1)];
    }

    if(leftDirection) {                     // Голова перемещается в любом из 4 направлений. Например, перемещаем голову змеи влево:
        x[0] -= DOT_SIZE;
    }

    if(rightDirection) {
        x[0] += DOT_SIZE;
    }

    if(upDirection) {
        y[0] -= DOT_SIZE;
    }

    if(downDirection) {
        y[0] += DOT_SIZE;
    }
}

void Snake::checkCollision()
/*В методе checkCollision() мы определяем, столкнулась ли змея со стеной или со своим телом.
* Если змея ударится головой о какую-нибудь «часть» своего тела, то игра окончена:*/
{
    for(int z = dots; z > 0; z--) {
        if((z > 4)
            && (x[0] == x[z])
            && (y[0] == y[z]))
        {
            inGame = false;
        }
    }

    if(y[0] >= B_HEIGHT) {                  // Игра заканчивается, если змея сталкивается с любой частью доски, например, с нижней:
        inGame = false;
    }

    if(y[0] < 0) {
        inGame = false;
    }

    if(x[0] >= B_WIDTH) {
        inGame = false;
    }

    if(x[0] < 0) {
        inGame = false;
    }

    if(!inGame) {
        killTimer(timerID);
    }
}

void Snake::locateApple()
{
   // QTime time = QTime::currentTime();
   //qsrand((uint) time.msec());
   int r = QRandomGenerator::global()->/*bounded(100)*/generate() % RAND_POS;
    apple_x = (r * DOT_SIZE);

   r = QRandomGenerator::global()->/*bounded(100)*/generate() % RAND_POS;
    apple_y = (r * DOT_SIZE);
}

void Snake::timerEvent([[maybe_unused]] QTimerEvent *e)
{
    if(inGame) {
        checkApple();
        checkCollision();
        move();
    }

    repaint();
}

void Snake::keyPressEvent(QKeyEvent *e)
{
    int key = e->key();


    // Например, если пользователь нажимает стрелочку ←, то мы устанавливаем значение true для переменной leftDirection.
    //    Эта переменная используется в функции move() для изменения координат змеи.
    // Стоит отметить, что когда змея направляется вправо, мы не можем сразу же повернуть налево (т.е. сразу развернуться на 180 градусов):
    if((key == Qt::Key_Left)
        && (!rightDirection))
    {
        leftDirection = true;
        upDirection = false;
        downDirection = false;
    }

    if((key == Qt::Key_Right)
        && (!leftDirection))
    {
        rightDirection = true;
        upDirection = false;
        downDirection = false;
    }

    if((key == Qt::Key_Up)
        && (!downDirection))
    {
        upDirection = true;
        rightDirection = false;
        leftDirection = false;
    }

    if((key == Qt::Key_Down)
        && (!upDirection))
    {
        downDirection = true;
        rightDirection = false;
        leftDirection = false;
    }

    QWidget::keyPressEvent(e);
}
