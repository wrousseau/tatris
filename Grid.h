#ifndef GRID_H
#define GRID_H
#include "Structures.h"
#include "qpainter.h"

enum
{
    GRID_HEIGHT = 22,
    GRID_WIDTH = 10

};




class Grid {

private :
    blockColor area[GRID_HEIGHT][GRID_WIDTH];

public:


    bool isFree(point par1);

    static bool isInBounds(int par1, int par2);

    bool isNotOccupied(point par1);

    bool isLineFull(int line);

};

#endif // GRID_H
