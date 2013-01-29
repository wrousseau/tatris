#ifndef TETRIMONO_H
#define TETRIMONO_H

#include "Structures.h"
#include "Grid.h"
#include <vector>

class Tetrimono
{
   protected:

    point coord;
    int rotation;
    bool onScreen, onFloor;
    int numberOfBlocks;
    int farthests[4]; // left, right, up, down
    char values[5][5];



public:

    virtual void initializeValues() = 0;

    bool isOnScreen();

    bool isOnFloor();

    char getValues(int i, int j);

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

    virtual ~Tetrimono(){};


};

class SquareTetrimono: public Tetrimono
{
private:

public:

    SquareTetrimono();

    void initializeValues();
};

#endif // TETRIMONO_H
