#ifndef LEVEL3_H
#define LEVEL3_H

#include "level1.h"
#include "hardblocks.h"
#include "bombblocks.h"
#include "deadlyblocks.h"

using namespace std;

class level3 : public level1
{
public:
    level3();
    void render();
    void setIDs();
    std::vector<Blocks*> findAdjacentBlocks(BombBlocks* B);
    void bombHandleCollision();


};

#endif // LEVEL3_H
