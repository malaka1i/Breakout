#include "level5.h"
#include "ball.h"
#define ROW 24
#define COL 18

level5::level5()  {}

void level5 :: setIDs(){

    //setting the ids if different objects
    for (int i =0; i<ROW; i++){
        for (int j=0; j<COL; j++){
            if (tiles [i][j]==1){
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
