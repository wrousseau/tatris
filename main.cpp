
#include "GameWindow.h"
#include "Game.h"
#include "Grid.h"
#include "Tetrimono.h"
#include <QApplication>
#include <time.h>

Game game;// = new Game();// on la met en globale, la base

int main(int argc, char *argv[])
{
    srand ( time(NULL) );

    QApplication app(argc, argv);

    int i = rand() % 3;
    Grid* grille = new Grid();
    game.setGrid(grille);
    Tetrimono nextBlock(i, grille);

    GameWindow gameWindow(nextBlock,grille);

    gameWindow.show();





    exit(app.exec());
}
