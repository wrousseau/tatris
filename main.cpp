
#include "GameWindow.h"
#include "Game.h"
#include "Grid.h"
#include "Tetrimono.h"
#include <QApplication>
#include <time.h>


int main(int argc, char *argv[])
{
    srand ( time(NULL) );

    QApplication app(argc, argv);

    Game* game = new Game();

    int i = rand() % 3;
    Grid* grille = new Grid();
    Tetrimono nextBlock(i, grille);

    GameWindow gameWindow(nextBlock,grille);

    gameWindow.show();





    return app.exec();
}
