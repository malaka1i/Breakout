#ifndef BALL_H
#define BALL_H
#include <object.h>
#include <QGraphicsTextItem>
#include<QTimer>
#include "hardblocks.h"
#include "bombblocks.h"
#include "deadlyblocks.h"
#include "barrier.h"

class level1;

class Ball:public QObject,  public Object
{

    Q_OBJECT
private:
    double xVelocity;
    double yVelocity;
    level1* l1;
    QTimer* timer;
    bool on;


    // private methods
    void reverseVelocityIfOutOfBounds();
    void handlePaddleCollision();
    void handleBlockCollision();
    void handleBarrierCollision();
    const int healthItemSpacing = 20; // Spacing between health items
    const int healthItemPositionX = 10; // X-coordinate for health item position
    const int healthItemPositionY = 10; // Y-coordinate for health item position
public:
    Ball(level1* l1);
    void stop();
    void start();
    int health;
    std::vector<QGraphicsPixmapItem*> healthItems;    // Vector of QPixmapItems for health representation
    void addHealthItem();
    void loseHealth();

    int score;


public slots:
    // public slots
    void move();

signals:
    void gameOver();
};

#endif // BALL_H
