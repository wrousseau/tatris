#ifndef TETRIMONO_H
#define TETRIMONO_H

#include "Structures.h"
#include <vector>

class Tetrimono
{
   protected:

    point coord;
    int rotation;
    bool onScreen, onFloor;
    int numberOfBlocks;
    int farthests[4]; // left, right, up, down



public:


    char*** values;

    virtual void initializeValues() = 0;

    bool isOnScreen() {
        return onScreen;
    }
    bool isOnFloor() {
        return onFloor;
    }

    int getX() {
        return coord.x1;
    }

    int getLeftBound() {
        return coord.x1 + farthests[0];
    }

    int getRightBound() {
        return coord.x1 + 100 - farthests[1];
    }

    int getUpperBound() {
        return coord.x2 + farthests[2];
    }

    int getLowerBound() {
        return coord.x2 + 100 - farthests[3];
    }

    int getY() {
        return coord.x2;
    }

    void setX(int par1) {
        coord.x1 = par1;
    }

    void setY(int par1) {

        coord.x2 = par1;
    }

    int fall(int par1) {
        if (Grid::isInBounds(getX(),getLowerBound()+par1)) {
        coord.x2 += par1;
        return 1;
        }
        return 0;
    }

    int moveLeft() {
        if (Grid::isInBounds(getLeftBound()-25,coord.x2)) {
        coord.x1 -= 25;
        return 1;
        }
        return 0;
    }

    int moveRight() {
        if (Grid::isInBounds(getRightBound()+25,coord.x2)){
        coord.x1 =+ 25;
        return 1;
        }
        return 0;
    }

    virtual ~Tetrimono(){};


};

class SquareTetrimono: public Tetrimono
{
private:

public:
    SquareTetrimono() {
        numberOfBlocks = 4;
        initializeValues();
    }



    void initializeValues() {
        values = &valuesEnumeration;
        farthests[0] = 50;
        farthests[1] = 25;
        farthests[2] = 50;
        farthests[3] = 25;


    }
};

#endif // TETRIMONO_H
