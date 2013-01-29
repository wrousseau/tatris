#include "Grid.h"


bool Grid::isInBounds(int par1, int par2) {
    if (par1 <= GRID_WIDTH*25 && par1 >= 0 && par2 <= GRID_HEIGHT*25 && par2 >= 0) {

        return true;
    }
    else {
        return false;
    }
}

bool Grid::isFree(point par1)
{
    if (isInBounds(par1.x1,par1.x2) && isNotOccupied(par1)) {
        return true;
    }
    else {
        return false;
    }
}


bool Grid::isNotOccupied(point par1) {
    if(area[par1.x1][par1.x2] == RED)
        return true;
    else
        return false;
}

bool Grid::isLineFull(int line){
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

/*void Grid::fillGrid(Tetrimono par1Tetrimono) {
    for (int i = 0; i < 5; i ++) {
        for (int j = 0; j < 5; j ++) {
            areacurrentTetrimono.getValues(i, j) != 0) {

        }
    }
}*/
