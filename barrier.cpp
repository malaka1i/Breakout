#include "barrier.h"

Barrier::Barrier(){
    QPixmap barrierImg(":/new/images/steelbarrier.png");
    barrierImg= barrierImg.scaledToHeight(60);
    barrierImg= barrierImg.scaledToWidth(160);
    setPixmap(barrierImg);
}
