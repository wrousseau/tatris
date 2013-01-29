
#include "GameWindow.h"
#include "Game.h"
#include "Tetrimono.h"
#include <QApplication>
#include <time.h>


int main(int argc, char *argv[])
{
    srand ( time(NULL) );

    QApplication app(argc, argv);

    Game* game = new Game();

    int i = rand() % 2;
    Tetrimono nextBlock(i);

    GameWindow gameWindow(nextBlock);

    gameWindow.show();





    return app.exec();
}
