#include "Tetrimono.h"
#include "QDebug"
#include "Grid.h"


Tetrimono::Tetrimono(int par1, Grid* par2Grid) {
    onFloor = false;
    coord.x1=0;
    coord.x2=0;
    rotation = 0;
    grid = par2Grid;
    blockType = par1;
    farthests[0] = 125;// par défaut on le met à 5 cases (125px)
    farthests[1] = 125;
    farthests[2] = 125;
    farthests[3] = 125;
    initializeValues(par1, 0);
}

Tetrimono::~Tetrimono() {
}

void Tetrimono::initializeValues(int par1, int par2) {
    int count = 0;
    for(int i=0; i<5; i++){
        for(int j=0; j<5 ; j++){
            values[i][j]=valuesEnumeration[par1][par2][i][j]; //cf Structures.h
            if (values[i][j] != 0) {
                if(farthests[0] >= j*25)
                    farthests[0] = j*25;
                if(farthests[1] >= (125-j*25))
                    farthests[1] = (125-j*25-25);
                if(farthests[2] >= i*25)
                    farthests[2] = i*25;
                if(farthests[3] >= (125-i*25))
                    farthests[3] = (125-i*25-25);
            }
        }
    }

}

void Tetrimono::rotate() {
    rotation = (rotation + 1) % 4;
    initializeValues(blockType, rotation);
}

bool Tetrimono::isOnScreen() {
    return onScreen;
}
bool Tetrimono::isOnFloor() {
    return onFloor;
}

short Tetrimono::getValues(int i, int j){
    return values[i][j];
}

int Tetrimono::getX() {
    return coord.x1;
}

int Tetrimono::getLeftBound() {
    return coord.x1 + farthests[0];
}

int Tetrimono::getRightBound() {
    return coord.x1 + 125 - farthests[1];
}

int Tetrimono::getUpperBound() {
    return coord.x2 + farthests[2];
}

int Tetrimono::getLowerBound() {
    return coord.x2 + 125 - farthests[3];
}

int Tetrimono::getY() {
    return coord.x2;
}

void Tetrimono::setX(int par1) {
    coord.x1 = par1;
}

void Tetrimono::setY(int par1) {

    coord.x2 = par1;
}

int Tetrimono::fall(int par1) {
    if (grid->isInBounds(getLeftBound(),getLowerBound()+par1)) {
        coord.x2 += par1;
        return 1;
    }
    if (!onFloor) {
        onFloor = true;
        grid->fillGrid(this);
        qDebug() << "heeere";
        grid->setHighest(grid->getHighest() - (125 - farthests[3] - farthests[2])/25); // SEG_FAULT
        qDebug() << "babouche";
    }
    return 0;
}

int Tetrimono::moveLeft() {
    if (grid->isInBounds(getLeftBound()-25,coord.x2) && !onFloor) {
    coord.x1 -= 25;
    return 1;
    }
    return 0;
}

int Tetrimono::moveRight() {
    if (grid->isInBounds(getRightBound()+25,coord.x2) && !onFloor){
    coord.x1 += 25;
    return 1;
    }
    return 0;
}

