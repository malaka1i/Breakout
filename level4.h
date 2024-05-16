#ifndef LEVEL4_H
#define LEVEL4_H
#include <QGraphicsPixmapItem>
#include "level1.h"
#include "hardblocks.h"
#include "bombblocks.h"
#include "barrier.h"
class level4 : public level1
{    
public:
    Barrier* barrier1;
    Barrier* barrier2;
    level4();
    void render();
    void setIDs();
    std::vector<Blocks*> findAdjacentBlocks(BombBlocks* B);
    void bombHandleCollision();
};

#endif // LEVEL4_H
