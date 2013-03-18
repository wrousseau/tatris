#ifndef GRIDFRAME_H
#define GRIDFRAME_H

/*!
 * \file GridFrame.h
 * \brief Jeu TAtris basé sur Tétris
 * \author Simon MANCHEL, Woody ROUSSEAU
 * \version 1.0
 */


#include <QFrame>
#include "qpainter.h"
#include "QKeyEvent"
#include "QTimer"
#include "Structures.h"
#include "Grid.h"
#include "Tetrimono.h"
#include "Game.h"
#include "MainWindow.h"

extern QString globalPath;

class GridFrame : public QFrame
{
    Q_OBJECT

private:
    point coord;
    Tetrimono *currentTetrimono;
    Grid *grid;
    bool isPlaying;
    QTimer *timer;// timer entre chaque fall du Tetrimono
    QTimer *fallingTimer;
    Game *currentGame;
    int nextTetrimonoNumber;
    bool hasLost;
    int timerForGameOver;
    QMediaPlayer* music;
    QMediaPlayer* gameOverSound;


public:
    /*!
     *  \brief Constructeur GridFrame
     *  \param parent : pointeur vers la Qframe parente. Egale à NULL par défaut)
     */
    explicit GridFrame(QWidget *parent = 0);
    /*!
     *  \brief Destructeur GridFrame
     */
    ~GridFrame();
    /*!
     *  \brief Initialisation des pointeurs vers les objets utilisés
     *  \param par1Game : Pointeur vers la partie en cours
     *  par2Grid : Pointeur vers la grille utilisée
     *  par3Tetrimono : Pointeur vers le Tétrimono utilisé pour la chute
     *  par4 : Numéro d'identification du prochain Tétrimono
     */
    void setObjects(Game* par1Game, Grid* par2Grid, Tetrimono* par3Tetrimono, int par4);
    /*!
     *  \brief Initialise le pinceau
     *
     *  Permet de configurer le pinceau Qt pour l'affichage
     *  \param color : couleur de type blockColor
     *  p : Objet QPainter servant à l'affichage
     */
    void setBrush(blockColor color, QPainter &p);
    /*!
     *  \brief Pause
     *
     *  Met le jeu en pause ou reprend la partie
     */
    void pause();
    /*!
     *  \brief Réglage du timer
     *  \param par1 : Temps en ms
     */
    void setTimer(int par1);
    /*!
     *  \brief Etablissement de l'état de la partie
     *  \param par1 : Vrai = a perdu, Faux = partie en cours
     */
    void setGameState(bool par1);
    /*!
     *  \brief Accesseur Timer
     *  \return Temps restant avant la fin du timer (ms)
     */
    int getTimer();
    
signals:
    void updateNextBlock(int par1);
    void goToMenuSignal();

    
public slots:
    /*!
     *  \brief Affichage
     *
     *  Gère l'affichage graphique
     */
    void paintEvent(QPaintEvent*);
    /*!
     *  \brief Gestion des entrées clavier
     *  \param k : Pointeur vers Objet de tyoe QKeyEvent contenant les informations de la saisie
     */
    void keyPressEvent( QKeyEvent *k );
    /*!
     *  \brief Similaire à paintEvent.
     */
    void keyReleaseEvent( QKeyEvent *k);
    /*!
     *  \brief Met à jour la partie
     *
     *  Après écoulement du timer, met à jour le score, effacement ligne, nouveau Tétrimono, etc
     */
    void update();
    /*!
     *  \brief Met à jour la chute
     *
     *  Met à jour la position verticale du Tétrimono
     */
    void updateFalling();

};

extern Game game;

#endif // GRIDFRAME_H
