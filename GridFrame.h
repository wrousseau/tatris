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
    Tetrimono currentTetrimono;

public:
    explicit GridFrame(QWidget *parent = 0);
    
signals:
    
public slots:
    void paintEvent(QPaintEvent*);
    void keyPressEvent( QKeyEvent *k );
    void update();
    void setTetrimono(Tetrimono& par1Tetrimono);
};

#endif // GRIDFRAME_H
