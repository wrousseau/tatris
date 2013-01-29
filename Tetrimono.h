#ifndef TETRIMONO_H
#define TETRIMONO_H

#include "Structures.h"
#include "Grid.h"
#include <vector>

class Tetrimono
{
   protected:

    point coord;
    int type;
    int rotation;
    bool onScreen, onFloor;
    int farthests[4]; // left, right, up, down
    char values[5][5];



public:

    Tetrimono(int par1) {
        onFloor = false;
        coord.x1=0;
        coord.x2=0;
        rotation = 0;
        farthests[0] = 125;
        farthests[1] = 125;
        farthests[2] = 125;
        farthests[3] = 125;
        initializeValues(par1, rotation);
    }


    bool isOnScreen();

    void initializeValues(int par1, int par2) {
        for(int i=0; i<5; i++){
            for(int j=0; j<5 ; j++){
                values[i][j]=valuesEnumeration[par1][par2][i][j];
                if (values[i][j] != 0) {
                    farthests[0] = (farthests[0] > j*25) ? j : farthests[0];
                    farthests[1] = (farthests[1] > (125-j*25)) ? (125-j*25) : farthests[1];
                    farthests[2] = (farthests[2] > i*25) ? i : farthests[2];
                    farthests[3] = (farthests[3] > (125-i*25)) ? (125-i*25) : farthests[3];
                }
            }
        }
    }

    char getValues(int i, int j) {
        return values[i][j];
    }


    void rotate() {
        rotation = (rotation + 1) % 4;
        initializeValues(type,rotation);
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


    ~Tetrimono(){};
};




#endif // TETRIMONO_H
