#ifndef BOMBBLOCKS_H
#define BOMBBLOCKS_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <vector>
#include "blocks.h"

class level1;

class BombBlocks : public Blocks {
    // Q_OBJECT
private:
    int collisionCount;
    bool isHitOnce;
    QPixmap bombPixmap;

public:

    BombBlocks(QString color);

    void handleCollision(level1* l);

    std::vector<Blocks*> findAdjacentBlocks(level1* l);
};
#endif // BOMBBLOCKS_H
