#ifndef BALL_H
#define BALL_H
#include <object.h>
#include<QTimer>
class level;
class Ball:public QObject,  public Object
{

    Q_OBJECT
    double xVelocity;
    double yVelocity;
    level*  level1;
    QTimer* timer;
    bool on;

    // private methods
    void reverseVelocityIfOutOfBounds();
    void handlePaddleCollision();
    void handleBlockCollision();
public:
    Ball(level* l);
    void stop();
    void start();

public slots:
    // public slots
    void move();
};

#endif // BALL_H
