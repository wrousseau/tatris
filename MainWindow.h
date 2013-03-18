#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*!
 * \file MainWindow.h
 * \brief Jeu TAtris basé sur Tétris
 * \author Simon MANCHEL, Woody ROUSSEAU
 * \version 1.0
 */

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "Game.h"
#include "GridFrame.h"


class Tetrimono;
class Grid;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    /*!
     *  \brief Constructeur MainWindow
     *  \param parent : Pointeur vers le parent de MainWindow. Par défaut égal à NULL
     */
    explicit MainWindow(QWidget *parent = 0);
    /*!
     *  \brief Destructeur MainWindow
     */
    ~MainWindow();
    /*!
     *  \brief Envoie les objets utilisés à GridFrame
     *  \param par1Game : Pointeur vers la partie en cours
     *  par2Grid : Pointeur vers la grille utilisée
     *  par3Tetrimono : Pointeur vers le Tétrimono utilisé pour la chute
     *  par4 : Numéro d'identification du prochain Tétrimono
     */
    void sendObjectsToGridFrame(Game* par1Game, Grid* par2Grid, Tetrimono* par3Tetrimono, int par4);
    /*!
     *  \brief Charge l'image du prochain Tétrimono
     */
    void loadTetrimonosImages();
    /*!
     *  \brief Renvoi le numéro d'identification du prochain Tétrimono
     */
    int getNextTetrimonoNumber();

public slots:
    void setNextTetrimonoNumber(int par1);

    /*!
     *  \brief Met à jour le level sur l'interface graphique
     *  \param Par1String : Level en QString
     *  \param par3 : Niveau en int
     */
    void updateLevel(QString par1String, int par2);


    void goToMenu();

signals:
    void goToMenuSignal();
    
private:
    Ui::MainWindow *ui;
    Game* currentGame;
    Grid* grid;
    Tetrimono* nextBlock;
    QImage tetrimonoImages[7];
    int nextTetrimonoNumber;
};

#endif // MAINWINDOW_H
