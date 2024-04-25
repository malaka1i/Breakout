#include "object.h"

Object::Object() {}
double Object::getCenterX(){
    return x() + boundingRect().width()/2;
}
