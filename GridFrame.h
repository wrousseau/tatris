#ifndef GRIDFRAME_H
#define GRIDFRAME_H

#include <QFrame>
#include "qpainter.h"
#include "QKeyEvent"
#include "QTimer"
#include "Structures.h"
#include "Grid.h"
#include "Tetrimono.h"

class GridFrame : public QFrame
{
    Q_OBJECT

private:
    point coord;
    SquareTetrimono currentTetrimono;

public:
    explicit GridFrame(QWidget *parent = 0);
    
signals:
    
public slots:
    void paintEvent(QPaintEvent*);
    void keyPressEvent( QKeyEvent *k );
    void update();


    
};

#endif // GRIDFRAME_H
