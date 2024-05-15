#ifndef LEVEL1_H
#define LEVEL1_H
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QObject>
#include "object.h"

#include "paddle.h"
#include "blocks.h"
#include "hardblocks.h"
#include<QTimer>
#include "GameOver.h"
class Ball;
using namespace std;
class level1 : public QGraphicsView
{
    Q_OBJECT
private:
public:

    QTimer* timer;
    Object* objects[12][12];
    int indeces[12][12];
    Ball* ball;
    GameOver* gameover;
    QGraphicsScene* scene;
    level1();
    virtual void render();
    virtual void setIDs();
    virtual void StartGame();
    bool gameStarted;
    Paddle* paddle;
    QGraphicsTextItem* scoretxt;
    QGraphicsTextItem* healthtxt;
    void haha()
    {

    }
public slots:
    void mouseMoveEvent(QMouseEvent* event) override;

    void mousePressEvent(QMouseEvent *event) override;
        void handleGameOver();


    protected slots:
        void handleTimeout()
        {
            StartGame();
            timer->disconnect();
        }




    };


#endif // LEVEL1_H
