#include "ball.h"
#include "level1.h"
// #include "level2.h"

// extern level1* l1;

Ball::Ball(level1* l): QObject(){

    //movement of ball bool
    on = false;

    name = "ball";
    l1 = l;
    id = 4;
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



    for (int i = 0; i < health; ++i) {
        QPixmap healthPixmap(":/new/images/health.png");
        healthPixmap = healthPixmap.scaled(20, 20);
        QGraphicsPixmapItem* healthTemp = new QGraphicsPixmapItem;
        healthTemp->setPixmap(healthPixmap);
        healthItems.push_back(healthTemp); // Add the health item to the scene and vector
        healthItems[i]->setPos(healthItemPositionX + i * healthItemSpacing, healthItemPositionY); // Set the position of the health item
        l1 -> scene->addItem(healthItems[i]);

    }

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
    double screenW = l1->width();
    double screenH = l1->height();

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
        loseHealth();
        if (health == 0) {
            emit gameOver();
        }
        qDebug() << "health is now" << health;
        stop();
        l1->gameStarted= false;
        setPos(500 , 400);
        l1->paddle->setPos( 480, 495);
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

            HardBlocks* hardblock = dynamic_cast<HardBlocks*>(cItems[i]);
            if (hardblock) {
                if(hardblock->isHitOnce){
                    score++;
                }
                hardblock->handleCollision();

            }

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
            if(!hardblock){
                l1->scene->removeItem(block);
                delete block;
                score ++;
            }


            l1->scoretxt->setPlainText("Score: " + QString::number(score));
            qDebug() << "score is now" << score;
        }
    }
}

void Ball :: addHealthItem() {
    if (health < 3) { // Check if health is not already at maximum
        health++; // Increase health
        healthItems[health - 1]->setPixmap(QPixmap(":/new/images/filled_heart.png")); // Replace with your filled health item image
        healthItems[health - 1]->setPos(healthItemPositionX, healthItemPositionY - health * healthItemSpacing); // Adjust the position of the added health item
    }
}


void Ball :: loseHealth() {
    if (health > 0) { // Check if health is not already zero
        health--; // Decrease health
        healthItems[health]->setPixmap(QPixmap(":/new/images/empty_heart.png")); // Replace with your empty health item image
        healthItems[health]->setPos(healthItemPositionX, healthItemPositionY + health * healthItemSpacing); // Adjust the position of the removed health item
    }
}
