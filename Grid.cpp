#include "Grid.h"
#include "Tetrimono.h"

Grid::Grid()
{
    highest = GRID_HEIGHT - 1;
    for (int i = 0; i < GRID_HEIGHT; i++)
    {
        for (int j = 0; j < GRID_WIDTH; j++)
        {
            area[i][j] = EMPTY;
        }
    }
}

bool Grid::isInBounds(int par1, int par2) {
    if (par1 <= (GRID_WIDTH-1)*25 && par1 >= 0 && par2 <= (GRID_HEIGHT-1)*25)
    {

        return true;
    }
    else
    {
        return false;
    }
}

bool Grid::isFree(point par1)
{
    if (isInBounds(par1.x1,par1.x2) && isNotOccupied(par1))
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool Grid::isNotOccupied(point par1)
{
    if(area[par1.x1][par1.x2] == RED)
        return true;
    else
        return false;
}

bool Grid::isLineFull(int line)
{
    bool test = true;
    int j=0;

    while(test && j < GRID_WIDTH)
    {
        if(area[line][j] == EMPTY)
            test = false;
        j++;
    }
    return test;
}

void Grid::fillGrid(Tetrimono* par1Tetrimono)
{
    for (int i = 0; i < 5; i ++) {
        for (int j = 0; j < 5; j ++) {
            if (par1Tetrimono->getValues(i,j) != 0) {
                area[par1Tetrimono->getY()/25+i][par1Tetrimono->getX()/25+j]=par1Tetrimono->getColor();
            }
        }
    }
}


blockColor Grid::getValues(int i, int j)
{
    return area[i][j];
}

int Grid::getHighest()
{
    return highest;
}

void Grid::setHighest(int par1)
{
    highest = par1;
}


void Grid::deleteLine(int i)
{
    for(int p=0 ; p < GRID_WIDTH ; p++)
    {//on met la ligne à EMPTY -> pas forcément utile, à vérifier
        area[i][p] = EMPTY;
    }

    for(int n=i ; n > 0 ; n--)
    { //On descend tout ce qui est au dessus d'une ligne /!\ Attention origine en haut
        for(int p=0 ; p < GRID_WIDTH ; p++)
        {
            area[n][p] = area[n-1][p];
        }
    }

    for(int p=0 ; p < GRID_WIDTH ; p++)
    { // on remet la ligne tout en haut à empty
        area[0][p] = EMPTY;
    }
return;
}

Grid::~Grid() {
}
