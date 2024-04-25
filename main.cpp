// #include "game.h"
#include "level.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Game w;
    // w.show();

    level* level1 = new level;
    level1->show();
    return a.exec();
}
