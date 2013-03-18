#ifndef GRIDFRAME_H
#define GRIDFRAME_H

#include <QFrame>
#include "qpainter.h"
#include "QKeyEvent"
#include "QTimer"
#include "Structures.h"
#include "Grid.h"
#include "Tetrimono.h"
#include "Game.h"
#include "MainWindow.h"

class GridFrame : public QFrame
{
    Q_OBJECT

private:
    point coord;
    Tetrimono *currentTetrimono;
    Grid *grid;
    bool isPlaying;
    QTimer *timer;
    QTimer *fallingTimer;
    Game *currentGame;
    int nextTetrimonoNumber;
    bool hasLost;
    int timerForGameOver;
    QMediaPlayer* music;
    QMediaPlayer* gameOverSound;


public:
    explicit GridFrame(QWidget *parent = 0);
    void setNextTetrimonoNumber(int par1);
    void setTetrimono(Tetrimono* par1Tetrimono);
    void setGrid(Grid* par1Grid);
    void setGame(Game* par1Game);
    void setBrush(blockColor color, QPainter &p);
    void pause();
    void setTimer(int par1);
    void setGameState(bool par1);
    int getTimer();
    
signals:
    void updateNextBlock(int par1);
    void goToMenuSignal();

    
public slots:
    void paintEvent(QPaintEvent*);
    void keyPressEvent( QKeyEvent *k );
    void keyReleaseEvent( QKeyEvent *k);
    void update();
    void updateFalling();

};

extern Game game;

#endif // GRIDFRAME_H
