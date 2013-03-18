#ifndef PARTIE_H
#define PARTIE_H

/*!
 * \file Game.h
 * \brief Jeu TAtris basé sur Tétris
 * \author Simon MANCHEL, Woody ROUSSEAU
 * \version 1.0
 */

#include "Grid.h"
#include <QMediaPlayer>
#include <QObject>
#include <QDir>

extern QString globalPath;

class Game: public QObject {

    Q_OBJECT

private:
    unsigned level;
    int score;
    unsigned deletedLines;
    bool gameOn;
    Grid* grid;
    QMediaPlayer *oneLineSound;
    QMediaPlayer *fourLinesSound;

signals:
    void updateScore(int i);
    void updateLevel(QString par1);


public:
        /*!
         *  \brief Constructeur Game
         *  \param par1Grid : pointeur vers la grille utilisée pour la partie
         */
    Game(Grid* par1Grid);
    /*!
     *  \brief Destructeur Game
     */
    ~Game();
    /*!
     *  \brief Accesseur Level
     *  \return Niveau atteint dans la partie
     */
    unsigned getLevel();
    /*!
     *  \brief Mutateur Level
     *  \param par1 : Nouveau niveau de la partie
     */
    void setLevel(unsigned par1);
    /*!
     *  \brief Monte le niveau de la partie en cours de 1
     */
    void levelUp();
    /*!
     *  \brief Accesseur Score
     *  \return Score atteint par le joueur dans cette partie
     */
    int getScore();
    /*!
     *  \brief Met à jour le score
     *  \param par1 : variation relative du score. Par exemple par1 = -2 entraine une diminution du score de 2
     */
    void addToScore(int par1);
    /*!
     *  \brief Fin de la partie
     *
     *  Procède aux procédures d'arrêt de la partie
     *  \return score
     */
    int gameOver();
    /*!
     *  \brief Accesseur Partie en cours
     *  \return Vrai si la partie est active, Faux sinon
     */
    bool isGameOn();
    /*!
     *  \brief Mutateur Grille
     *
     *  Permet de (re)définir la grille utilisée
     *  \param parGrid : pointeur vers la grille utilisée
     */
    void setGrid(Grid* parGrid);
    /*!
     *  \brief Gestionnaire du Score
     *
     *  Gère les suppressions de lignes et le score
     */
    void scoreManage();
    /*!
     *  \brief Gestion des Niveaux
     *
     *  Permet de passer aux niveaux supérieur et transmet l'information à l'affichage
     */
    void checkScore(); // Gère le Passage au Niveau Supérieur

};

#endif // PARTIE_H
