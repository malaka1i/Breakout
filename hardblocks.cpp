#include "hardblocks.h"

HardBlocks:: HardBlocks(QString color) : Blocks(color) {
    collisionCount = 0;
    id=2;
    isHitOnce = false;
    changedPixmap = QPixmap(":/new/images/broken"+color+".png"); // Replace with your changed block image
}

void HardBlocks:: handleCollision() {
    if (collisionCount==1)
    {
        scene()->removeItem(this);
        delete this;
    } else {

        if(collisionCount == 0) {

            isHitOnce = true;
            pixmap() = changedPixmap;


        }

        collisionCount++;

    }
}

