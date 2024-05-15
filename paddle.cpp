#include "paddle.h"

Paddle::Paddle() {
    id=3;
    QPixmap paddleimg(":/new/images/paddle1.png");
    paddleimg= paddleimg.scaledToHeight(60); //orgininally 60
    paddleimg= paddleimg.scaledToWidth(80); //originally 80
    setPixmap(paddleimg);
}
