
#include "MainWindow.h"
#include "Game.h"
#include "Grid.h"
#include "Tetrimono.h"
#include <QApplication>
#include <QtWidgets>
#include <time.h>

Game game;// = new Game();// on la met en globale, la base

int main(int argc, char *argv[])
{
    srand ( time(NULL) );

    QApplication app(argc, argv);
    app.setApplicationName("TAtris");

    MainWindow gameWindow;
    gameWindow.show();

    exit(app.exec());
}
