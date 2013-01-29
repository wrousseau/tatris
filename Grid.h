#ifndef GRID_H
#define GRID_H
#include "Structures.h"
#include "qpainter.h"




class Grid {

public:
    static const int GRID_HEIGHT = 22;
    static const int GRID_WIDTH = 10;

private :
    blockColor area[GRID_HEIGHT][GRID_WIDTH];

public:


    bool isFree(point par1)
    {
        if (isInBounds(par1.x1,par1.x2) && isNotOccupied(par1)) {
            return true;
        }
        else {
            return false;
        }
    }

    static bool isInBounds(int par1, int par2) {
        if (par1 <= GRID_WIDTH*25 && par1 >= 0 && par2 <= GRID_HEIGHT*25 && par2 >= 0) {

            return true;
        }
        else {
            return false;
        }
    }

    bool isNotOccupied(point par1) {
        if(area[par1.x1][par1.x2] == EMPTY)
            return true;
        else
            return false;
    }

    bool isLineFull(int line){
        bool test = true;
        int i=0;

        while(test)
        {
            if(area[i][line] == EMPTY)
                test = false;
            i++;
        }
        return test;
    }


};

#endif // GRID_H
