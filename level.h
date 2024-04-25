#ifndef LEVEL_H
#define LEVEL_H
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QObject>
#include "object.h"
#include "ball.h"
#include "paddle.h"
#include "blocks.h"
#include<QTimer>
#include "GameOver.h"

using namespace std;
class level : public QGraphicsView
{
    Q_OBJECT
    QTimer* timer;
    Object* objects[12][12];
    int indeces[12][12];
    Ball* ball;
    GameOver* gameover;

public:

    QGraphicsScene* scene;
    level();
    void render();
    void setIDs();
    void StartGame();
    bool gameStarted;
    Paddle* paddle;
   QGraphicsTextItem* scoretxt;
   QGraphicsTextItem* healthtxt;


public slots:
    void mouseMoveEvent(QMouseEvent* event) override;

    void mousePressEvent(QMouseEvent *event) override
    {

        // If the mouse is clicked, stop the timer and start the game
        if (!gameStarted) {
            timer->stop();
            paddle->setPos( 480, 495);
            ball->start();
            qDebug() << "Mouse clicked! Timer stopped. Starting the game...";
            gameStarted = true;
            // Implement your game logic here
            }

        }

    void handleGameOver();


private slots:
    void handleTimeout()
    {
        StartGame();
        timer->disconnect();
    }




};

#endif // LEVEL_H
