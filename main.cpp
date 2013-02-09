#include "MainWindow.h"
#include <QApplication>
#include <time.h>


int main(int argc, char *argv[])
{
    srand ( time(NULL) ); // Initialisation de la Fonction Random


    QApplication app(argc, argv);
    app.setApplicationName("TAtris");

    MainWindow gameWindow; // Initialisation de la fenêtre principale
    gameWindow.show();

    exit(app.exec()); // Sortie de l'Application
}
