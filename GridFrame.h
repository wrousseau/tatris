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

extern QString globalPath;
extern QString currentTheme;

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
public:
    QMediaPlayer* music;
    QMediaPlayer* gameOverSound;


public:
    explicit GridFrame(QWidget *parent = 0);
    ~GridFrame();
    void setObjects(Game* par1Game, Grid* par2Grid, Tetrimono* par3Tetrimono, int par4);
    void setBrush(blockColor color, QPainter &p);
    void setTimer(int par1);
    void setGameState(bool par1);
    int getTimer();
    void showPauseMenu();

    
signals:
    void updateNextBlock(int par1);
    void goToMenuSignal();

    
public slots:
    void paintEvent(QPaintEvent*);
    void keyPressEvent( QKeyEvent *k );
    void keyReleaseEvent( QKeyEvent *k);
    void update();
    void updateFalling();
    void replayMusic(QMediaPlayer::MediaStatus status);
    void pause();



};

extern Game game;

#endif // GRIDFRAME_H
