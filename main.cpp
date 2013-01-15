
#include "GameWindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication game(argc, argv);
    GameWindow gameWindow;

    gameWindow.show();
    
    return game.exec();
}
