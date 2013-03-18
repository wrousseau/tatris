#include "MainWindow.h"
#include <QApplication>
#include <time.h>
#include <QString>
#include <QDir>



QString globalPath;

int main(int argc, char *argv[])
{
    srand ( time(NULL) ); // Initialisation de la Fonction Random

    //Gestion des dossiers
    QDir path(QDir::currentPath());
    QString optionnalPath("/tatris/ressources/");
    path.cdUp();
    globalPath = path.absolutePath() + optionnalPath;

    QApplication app(argc, argv);
    app.setApplicationName("TAtris");

    MainWindow gameWindow; // Initialisation de la fenêtre principale
    gameWindow.show();

    exit(app.exec()); // Sortie de l'Application
}
