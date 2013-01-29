
#include "GameWindow.h"
#include "Game.h"
//#include "Tetrimono.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Game* game = new Game();
    GameWindow gameWindow;
    gameWindow.show();

    //Tetrimono* blockOnScreen = new Tetrimono();
    //while (!blockOnScreen->isOnFloor()) {

    //}



    return app.exec();
}
