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
    Game *currentGame;
    int nextTetrimonoNumber;

public:
    explicit GridFrame(QWidget *parent = 0);
    void setNextTetrimonoNumber(int par1);
    void setTetrimono(Tetrimono* par1Tetrimono);
    void setGrid(Grid* par1Grid);
    void setGame(Game* par1Game);
    void setBrush(blockColor color, QPainter &p);
    void pause();
    void setTimer(int par1);
    
signals:
    void updateNextBlock(int par1);

    
public slots:
    void paintEvent(QPaintEvent*);
    void keyPressEvent( QKeyEvent *k );
    void update();

};

extern Game game;

#endif // GRIDFRAME_H
