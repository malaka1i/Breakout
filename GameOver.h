#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>


class GameOver : public QGraphicsPixmapItem {
public:
    GameOver(QGraphicsScene* scene) : QGraphicsPixmapItem() {
        setPixmap(QPixmap(":/new/images/GameOver.png"));
        setPos(scene->width() / 2 - pixmap().width() / 2, scene->height() / 2 - pixmap().height() / 2);
        scene->addItem(this);
    }

    // void fadeOut() {
    //     setOpacity(opacity() - 0.1);
    //     if (opacity() > 0) {
    //         // Restart the timer with a shorter delay to repeat the fading effect
    //         timer->start(50);
    //     } else {
    //         scene()->clear(); // Clear the scene or perform any necessary cleanup
    //         deleteLater(); // Delete the GameOver object when done
    //     }
    // }

private:
    // QTimer* timer = new QTimer();

};

#endif // GAMEOVER_H
