#include "Tetrimono.h"

bool Tetrimono::isOnScreen() {
    return onScreen;
}
bool Tetrimono::isOnFloor() {
    return onFloor;
}

char Tetrimono::getValues(int i, int j){
    return values[i][j];
}

int Tetrimono::getX() {
    return coord.x1;
}

int Tetrimono::getLeftBound() {
    return coord.x1 + farthests[0];
}

int Tetrimono::getRightBound() {
    return coord.x1 + 100 - farthests[1];
}

int Tetrimono::getUpperBound() {
    return coord.x2 + farthests[2];
}

int Tetrimono::getLowerBound() {
    return coord.x2 + 100 - farthests[3];
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
    if (Grid::isInBounds(getX(),getLowerBound()+par1)) {
    coord.x2 += par1;
    return 1;
    }
    return 0;
}

int Tetrimono::moveLeft() {
    if (Grid::isInBounds(getLeftBound()-25,coord.x2)) {
    coord.x1 -= 25;
    return 1;
    }
    return 0;
}

int Tetrimono::moveRight() {
    if (Grid::isInBounds(getRightBound()+25,coord.x2)){
    coord.x1 =+ 25;
    return 1;
    }
    return 0;
}


//------------SquareTetrimono

SquareTetrimono::SquareTetrimono() {
    numberOfBlocks = 4;
    initializeValues();
}



void SquareTetrimono::initializeValues() {
    for(int i=0; i<5; i++){
        for(int j=0; j<5 ; j++){
            values[i][j]=valuesEnumeration[0][0][i][j];
        }
    }
    farthests[0] = 50;
    farthests[1] = 25;
    farthests[2] = 50;
    farthests[3] = 25;


}
