#ifndef BLOCKS_H
#define BLOCKS_H
#include <object.h>
class Blocks : public Object {
    QString blockColor;
public:
    Blocks(QString = "");
    std::vector<Blocks*> findAdjacentBlocks();
    void setBlockScale(int H, int W);
};

#endif // BLOCKS_H
