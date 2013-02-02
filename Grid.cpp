#include "Grid.h"
#include "Tetrimono.h"
#include "QDebug"
#include <iostream>

Grid::Grid() {
    highest = GRID_HEIGHT - 1;
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            area[i][j] = 0;
        }
    }
}

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

void Grid::fillGrid(Tetrimono* par1Tetrimono) {
    for (int i = 0; i < 5; i ++) {
        for (int j = 0; j < 5; j ++) {
            if (par1Tetrimono->getValues(i,j) != 0) {
            area[par1Tetrimono->getX()/25+i][par1Tetrimono->getY()/25+j]=par1Tetrimono->getValues(i, j);
            qDebug() << "whhat";
            }

        }
    }

}

short Grid::getValues(int i, int j){
    return area[i][j];
}

int Grid::getHighest() {
    return highest;
}

void Grid::setHighest(int par1) {
    highest = par1;
}

void Grid::printArea() {
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            std::cout << area[i][j] << " ";
        }
        std::cout << "\n";
    }
}

Grid::~Grid() {
}
