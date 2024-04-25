#include "blocks.h"

Blocks::Blocks(QString color) {

    name = "block";
    id =1;

    QPixmap blockimg(":/new/images/"+color+"block.png");
    blockimg= blockimg.scaledToHeight(60);
    blockimg= blockimg.scaledToWidth(80);
    setPixmap(blockimg);

    blockColor = color;
}
