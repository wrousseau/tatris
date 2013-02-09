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

public:
    explicit GridFrame(QWidget *parent = 0);
    
signals:

    
public slots:
    void paintEvent(QPaintEvent*);
    void keyPressEvent( QKeyEvent *k );
    void update();
    void setTetrimono(Tetrimono* par1Tetrimono);
    void setGrid(Grid* par1Grid);
    void setGame(Game* par1Game);

    void setBrush(blockColor color, QPainter &p);
    void pause();
};

extern Game game;

#endif // GRIDFRAME_H
