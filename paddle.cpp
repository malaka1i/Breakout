#include "paddle.h"

Paddle::Paddle() {
    id=2;
    QPixmap paddleimg(":/new/images/paddle1.png");
    paddleimg= paddleimg.scaledToHeight(60);
    paddleimg= paddleimg.scaledToWidth(80);
    setPixmap(paddleimg);
}
