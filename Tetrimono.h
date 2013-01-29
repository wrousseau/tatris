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


    char values[5][5];

    virtual void initializeValues(int par1) = 0;

    void rotate() {
        rotation = (rotation + 1) % 4;
        initializeValues(rotation);
    }

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
        return coord.x1 + 125 - farthests[1];
    }

    int getUpperBound() {
        return coord.x2 + farthests[2];
    }

    int getLowerBound() {
        return coord.x2 + 125 - farthests[3];
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
        if (Grid::isInBounds(getLeftBound(),getLowerBound()+par1)) {
        coord.x2 += par1;
        if (getLowerBound() == 25*22) {
            onFloor = true;
        }
        return 1;
        }
        return 0;
    }

    int moveLeft() {
        if (Grid::isInBounds(getLeftBound()-25,coord.x2) && !onFloor) {
        coord.x1 -= 25;
        return 1;
        }
        return 0;
    }

    int moveRight() {
        if (Grid::isInBounds(getRightBound()+25,coord.x2) && !onFloor){
        coord.x1 += 25;
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
        onFloor = false;
        coord.x1=0;
        coord.x2=0;
        rotation = 0;
        initializeValues(rotation);
    }



    void initializeValues(int par1) {
        for(int i=0; i<5; i++){
            for(int j=0; j<5 ; j++){
                values[i][j]=valuesEnumeration[0][par1][i][j];
            }
        }
        farthests[0] = 50;
        farthests[1] = 25;
        farthests[2] = 50;
        farthests[3] = 25;
    }

};

#endif // TETRIMONO_H
