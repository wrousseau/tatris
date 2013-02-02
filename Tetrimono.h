#ifndef TETRIMONO_H
#define TETRIMONO_H

#include "Structures.h"
#include "Grid.h"

class Tetrimono
{
    protected:
        point coord;
        int blockType;
        int rotation;
        bool onScreen, onFloor;
        Grid* grid;
        int farthests[4]; // left, right, up, down
        short values[5][5];

    public:
        Tetrimono(int par1, Grid* par2Grid);
        void initializeValues(int par1, int par2);
        short getValues(int i, int j);
        void rotate();
        bool isOnScreen();
        bool isOnFloor();
        int getX();
        int getLeftBound();
        int getRightBound();
        int getUpperBound();
        int getLowerBound();
        int getY();
        void setX(int par1);
        void setY(int par1);
        int fall(int par1);
        int moveLeft();
        int moveRight();
        ~Tetrimono();

};






#endif // TETRIMONO_H
