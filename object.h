#ifndef OBJECT_H
#define OBJECT_H
#include <QGraphicsPixmapItem>
class Object : public QGraphicsPixmapItem
{
        // Q_OBJECT
protected:
    //the class is for any object created aka: ball, paddle and blocks
    QString name;

    //each  object type has a unique id (ex: block's id =0)
    int id;

public:
    Object();
    double getCenterX();


};

#endif // OBJECT_H
