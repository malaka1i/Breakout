// #include "game.h"
#include "level1.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Game w;
    // w.show();

    level1* l1 = new level1;
    l1->show();
    return a.exec();
}
