#include "level4.h"
#include "ball.h"
#define ROW 12
#define COL 12

level4::level4() {
    QPixmap barrierImg(":/new/images/steelbarrier.png");
    barrierImg= barrierImg.scaledToHeight(60);
    barrierImg= barrierImg.scaledToWidth(160);
    barrier1 = new Barrier;
    barrier2 = new Barrier;
}

void level4 :: setIDs(){

    //setting the ids if different objects
    for (int i =0; i<ROW; i++){
        for (int j=0; j<COL; j++){
            if (j>0 && j <= 5){
                if(i%3==0 & j%2==0){
                    indeces [i][j] = 2; //hard blocks
                }
                else if(i%4==0 & j%2==0){ //bomb blocks
                    indeces [i][j] = 7;
                }
                else indeces[i][j]=1 ; //normal blocks
            }

            //0 means it's empty
            else indeces[i][j] = 0 ;
        }
    }
}

void level4:: render(){
    //a vector of the colors of the blocks
    QVector<QString> BlockImgs = {"blue", "darkgreen", "green", "lightblue", "orange", "purple"};
    QVector<QString> BrokenBlockImgs = {"brown", "grey"}; //might delete later
    QString BombBlockImgs = "yellow"; //might delete later
    QString DeadlyBlockImgs = "red"; //might delete later

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
            else if(indeces[i][j] == 2){
                int colorindex=rand()% BrokenBlockImgs.length();
                objects[i][j]= new HardBlocks(BrokenBlockImgs[colorindex]);

                objects[i][j]->setPos( i*80,  j*45); //j originally 45
                scene->addItem(objects[i][j]);
            }
            else if(indeces[i][j] == 6){
                objects[i][j]= new HardBlocks(DeadlyBlockImgs);

                objects[i][j]->setPos( i*80,  j*45); //j originally 45
                scene->addItem(objects[i][j]);
            }
            else if(indeces[i][j] == 7){
                objects[i][j]= new HardBlocks(BombBlockImgs);

                objects[i][j]->setPos( i*80,  j*45); //j originally 45
                scene->addItem(objects[i][j]);
            }
        }
    }

    barrier1->setPos( 250, 0);
    scene->addItem(barrier1);

    barrier2->setPos( 250, 540-160);
    scene->addItem(barrier2);

    paddle->setPos( 480, 495);
    scene->addItem(paddle);


    scene->addItem(ball);
    ball->setPos(500 , 470);

    scoretxt = scene-> addText("Score: 0");
    scoretxt->setDefaultTextColor(Qt::red);
    scoretxt->setPos(600,10);
    scene->addItem(scoretxt);

}
