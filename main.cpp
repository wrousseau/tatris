#include "basefenetre.h"
#include "Grille.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication game(argc, argv);
    BaseFenetre mainWindow;

    mainWindow.show();
    
    return game.exec();
}
