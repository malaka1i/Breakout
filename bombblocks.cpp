#include "bombblocks.h"
#include "level1.h"
#define ROW 12
#define COL 12

BombBlocks:: BombBlocks(QString color) : Blocks(color) {
    id = 7;
    collisionCount = 0;
    isHitOnce = false;
    bombPixmap = QPixmap(":/new/images/bomb_block.png"); // Replace with your bomb block image
}

void BombBlocks:: handleCollision(level1* l) {
    if (!isHitOnce) {
        pixmap() = bombPixmap;
        isHitOnce = true;
        collisionCount++;
    } else if (collisionCount == 1) {
        // Remove adjacent blocks
        std::vector<Blocks*> adjacentBlocks = findAdjacentBlocks(l);
        for (Blocks* block : adjacentBlocks) {
            scene()->removeItem(block);
            delete block;
        }
        // Remove the bomb block itself
        scene()->removeItem(this);
        delete this;
    }
}

std::vector<Blocks*> BombBlocks::findAdjacentBlocks(level1* l) {
    std::vector<Blocks*> adjacentBlocks;
    // Get the center coordinates of the bomb block
    qreal centerX = x() + boundingRect().width() / 2;
    qreal centerY = y() + boundingRect().height() / 2;

    qreal blockWidth = 80;
    qreal blockHeight = 45;

    // Calculate the grid indices of the bomb block
    int blockX = static_cast<int>(centerX / blockWidth);
    int blockY = static_cast<int>(centerY / blockHeight);

    // Iterate over adjacent blocks in all directions
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) {
                continue; // Skip the bomb block itself
            }
            int adjacentX = blockX + i;
            int adjacentY = blockY + j;

            // Check if the adjacent block indices are within valid bounds
            if (adjacentX >= 0 && adjacentX < COL && adjacentY >= 0 && adjacentY < ROW) {
                // Calculate the position of the adjacent block
                qreal posX = adjacentX * blockWidth;
                qreal posY = adjacentY * blockHeight;

                // Retrieve the block at the calculated position from the scene
                QPointF scenePos(posX, posY);
                QList<QGraphicsItem*> items = l->scene->items(scenePos);
                // Find the Blocks* item from the list of items at the scene position
                for (QGraphicsItem* item : items) {
                    Blocks* block = dynamic_cast<Blocks*>(item);
                    if (block) {
                        adjacentBlocks.push_back(block);
                        break; // Stop after finding the first Blocks* item
                    }
                }
            }
        }
    }

    return adjacentBlocks;
}


