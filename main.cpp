/*!
 * \file main.cpp
 * \brief Jeu TAtris basé sur Tétris
 * \author Simon MANCHEL, Woody ROUSSEAU
 * \version 1.0
 */

#include "MenuWindow.h"
#include "OptionsWindow.h"
#include <QApplication>
#include <time.h>
#include <QDir>

QString globalPath;
bool isMusicOn = true;
bool areSoundsOn = true;
QString currentTheme = "salsa";

int main(int argc, char *argv[])
{
    srand ( time(NULL) ); // Initialisation de la Fonction Random

    // Accéder aux fichiers audios situés dans les sources
    QDir path(QDir::currentPath());
    QString optionnalPath("/tatris/ressources/audio/");
    #ifndef Q_OS_MAC
    path.cdUp();
    #else
    path.cd("../../../..");
    #endif
    globalPath = path.absolutePath() + optionnalPath;

    QApplication app(argc, argv);
    app.setApplicationName("TAtris");
    MenuWindow menuWindow; // Initialisation de la fenêtre de menu
    menuWindow.show();

    exit(app.exec()); // Sortie de l'Application
}
