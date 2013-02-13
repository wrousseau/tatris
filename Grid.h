#ifndef GRID_H
#define GRID_H
#include "Structures.h"
#include "qpainter.h"

class Tetrimono;

enum
{
    GRID_HEIGHT = 22,
    GRID_WIDTH = 10

};

class Grid {

private :
    blockColor area[GRID_HEIGHT][GRID_WIDTH]; // représente la grille des élements fixés
    int highest;

public:
    Grid();
    ~Grid();
    bool isFree(point par1);
    bool isInBounds(int par1, int par2);
    bool isNotOccupied(point par1);
    bool isLineFull(int line);
    void fillGrid(Tetrimono* par1Tetrimono);
    blockColor getValues(int i, int j);
    int getHighest();
    void setHighest(int par1);
    void deleteLine(int i);

};

#endif // GRID_H
