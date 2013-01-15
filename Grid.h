#ifndef GRID_H
#define GRID_H
#include "Structures.h"

const int GRID_HEIGHT = 22;
const int GRID_WIDTH = 10;


class Grid {

private :

    int area[GRID_HEIGHT][GRID_WIDTH] = {{0}};

public:

    bool isFree(point par1)
    {
        if (isInBounds(par1) && isNotOccupied(par1)) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isInBounds(par1) {
        if (par1.x1 <= GRID_HEIGHT && par1.x1 >= 0 && par1.x2 <= GRID_WIDTH && par1.x2 >= 0) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isNotOccupied(par1) {

    }


};

#endif // GRID_H
