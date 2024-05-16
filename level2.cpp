#include "level2.h"
#include "ball.h"
//the screen will be like a 12x12 matrix
#define ROW 12
#define COL 12

level2::level2(){}

//a function to set positions for each object to its place on the screen
void level2:: render(){
    //a vector of the colors of the blocks
    QVector<QString> BlockImgs = {"blue", "brown", "darkgreen", "green", "grey", "lightblue", "orange", "purple", "red", "yellow"};
    QVector<QString> BrokenBlockImgs = {"blue", "brown", "darkgreen", "green", "grey", "lightblue", "orange", "purple", "red", "yellow"}; //might delete later
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


void level2 :: setIDs(){

    //setting the ids if different objects
    for (int i =0; i<ROW; i++){
        for (int j=0; j<COL; j++){
            if (j>0 && j <= 5){
                if(i%3==0 & j%2==0){
                    indeces [i][j] = 2;

                }else indeces[i][j]=1 ;
            }
            //0 means it's empty
            else indeces[i][j] = 0 ;

        }
    }

}



