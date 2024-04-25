#include "ball.h"
#include "level.h"

Ball::Ball(level* l): QObject(){

    on = false;
    name = "ball";
    level1 = l;
    id = 3;
    QPixmap ballPic(":/new/images/Ball.png");
    ballPic = ballPic.scaled(25,25);
    setPixmap(ballPic);

    // move up right initially
    xVelocity = 0;
    yVelocity = -5;


     timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    health = 3;
    score = 0;

}



void Ball:: stop(){
    if(on){
        timer-> stop();
        on = !on;
    }
}

void Ball:: start(){
    if(!on){
        timer->start(15);
        on = !on;
    }
}

void Ball::move(){
    // if out of bounds, reverse the velocity
    reverseVelocityIfOutOfBounds();

    // if collides with paddle, reverse yVelocity, and add xVelocity
    // depending on where (in the x axis) the ball hits the paddle
    handlePaddleCollision();

    // handle collisions with blocks (destroy blocks and reverse ball velocity)
    handleBlockCollision();

    // moveBy(xVelocity,yVelocity);
    setPos(pos() + QPointF(xVelocity,yVelocity));
}

void Ball::reverseVelocityIfOutOfBounds(){
    // check if out of bound, if so, reverse the proper velocity
    double screenW = level1->width();
    double screenH = level1->height();

    // left edge
    if (mapToScene(boundingRect().topLeft()).x() <= 0){
        xVelocity = -1 * xVelocity;
    }

    // right edge
    if (mapToScene(boundingRect().topRight()).x() >= screenW){
        xVelocity = -1 * xVelocity;
    }

    // top edge
    if (mapToScene(boundingRect().topLeft()).y() <= 0){
        yVelocity = -1 * yVelocity;
    }

    // bottom edge
    if(mapToScene(boundingRect().topLeft()).y() >= screenH && health > 0){
        health--;
        qDebug() << "health is now" << health;
        stop();
        level1->gameStarted= false;
        setPos(500 , 400);
        level1->paddle->setPos( 480, 495);
    }
}

void Ball::handlePaddleCollision(){
    QList<QGraphicsItem*> cItems = collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i){
        Paddle* paddle = dynamic_cast<Paddle*>(cItems[i]);
        if (paddle){
            // collides with paddle

            // reverse the y velocity
            yVelocity = -1 * yVelocity;

            // add to x velocity depending on where it hits the paddle
            double ballX = getCenterX();
            double paddleX = paddle->getCenterX();

            double dvx = ballX - paddleX;
            xVelocity = (xVelocity + dvx)/15;

            return;
        }
    }
}

void Ball::handleBlockCollision(){
    QList<QGraphicsItem*> cItems = collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i){
        Blocks* block = dynamic_cast<Blocks*>(cItems[i]);
        // collides with block
        if (block){
            double yPad = 15;
            double xPad = 15;
            double ballx = pos().x();
            double bally = pos().y();
            double blockx = block->pos().x();
            double blocky = block->pos().y();

            // collides from bottom
            if (bally > blocky + yPad && yVelocity < 0){
                yVelocity = -1 * yVelocity;
            }

            // collides from top
            if (blocky > bally + yPad && yVelocity > 0 ){
                yVelocity = -1 * yVelocity;
            }

            // collides from right
            if (ballx > blockx + xPad && xVelocity < 0){
                xVelocity = -1 * xVelocity;
            }

            // collides from left
            if (blockx > ballx + xPad && xVelocity > 0){
                xVelocity = -1 * xVelocity;
            }

            // delete block(s)
            level1->scene->removeItem(block);
            delete block;
            score ++;
            qDebug() << "score is now" << score;
        }
    }
}

