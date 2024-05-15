#include "level1.h"
#include "ball.h"
//the screen will be like a 12x12 matrix
#define ROW 12
#define COL 12

level1::level1(){


    gameStarted = false;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &level1::handleTimeout);
    timer->start();

    setMouseTracking(true);

    //creating a scene
    scene = new QGraphicsScene();
    setScene(scene);
    setSceneRect(0,0,960,540);
    paddle = new Paddle;
}

//a function to set positions for each object to its place on the screen
void level1:: render(){
    //a vector of the colors of the blocks
    QVector<QString> BlockImgs = {"blue", "brown", "darkgreen", "green", "grey", "lightblue", "orange", "purple", "red", "yellow"};


    srand(time(0));

    //traverse the matrix and fill in the ids of the blocks in their place
    for (int i =0; i<COL; i++){
        for (int j=0; j<ROW; j++){
            if (indeces[i][j]==1){
                int colorindex=rand()% BlockImgs.length();
                objects[i][j]= new Blocks(BlockImgs[colorindex]);

                objects[i][j]->setPos( i*80,  j*45); //j originally 45
                scene->addItem(objects[i][j]);
            }

        }
    }

    paddle->setPos( 480, 495);
    scene->addItem(paddle);


    scene->addItem(ball);
    ball->setPos(500 , 470);

    scoretxt = scene-> addText("Score: 0");
    scoretxt->setDefaultTextColor(Qt::red);
    scoretxt->setPos(600,10);
    scene->addItem(scoretxt);






}


void level1 :: setIDs(){

    //setting the ids if different objects
    for (int i =0; i<ROW; i++){
        for (int j=0; j<COL; j++){
            if (j>0 && j <= 5){
                //1 is a block
                indeces[i][j]=1 ;
            }
            //0 means it's empty
            else indeces[i][j] = 0 ;

        }
    }

    indeces[COL/2][ROW-2]=2;
}

void level1::mouseMoveEvent(QMouseEvent* event){
    if(gameStarted){
        QPointF temp = mapToScene(event->pos());

        QPointF mousePos = temp.toPoint();
        qreal cursor = mousePos.x();
        paddle->setPos(cursor, paddle->y());

    }

}

void level1:: mousePressEvent(QMouseEvent *event)
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

void level1 :: StartGame(){

    ball = new Ball(this);

    setIDs();
    render();
    connect(ball, SIGNAL(gameOver()), this, SLOT(handleGameOver()));

}


void level1::handleGameOver() {
    gameover = new GameOver(scene);
}

