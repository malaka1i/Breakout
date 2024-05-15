#ifndef HARDBLOCKS_H
#define HARDBLOCKS_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <random>
#include "blocks.h"

class HardBlocks : public Blocks {

public:
    HardBlocks(QString color);
    void handleCollision();
    int collisionCount;
    bool isHitOnce;
    QPixmap changedPixmap;


};

#endif // HARDBLOCKS_H
