// #include "game.h"
#include "level2.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Game w;
    // w.show();

    level2* l1 = new level2;
    l1->show();
    return a.exec();
}
