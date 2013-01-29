#include "Tetrimono.h"

Tetrimono::Tetrimono(int par1) {
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

void Tetrimono::initializeValues(int par1, int par2) {
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

void Tetrimono::rotate() {
    rotation = (rotation + 1) % 4;
    initializeValues(type,rotation);
}

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
    if (Grid::isInBounds(getLeftBound(),getLowerBound()+par1)) {
    coord.x2 += par1;
    if (getLowerBound() == 25*22) {
        onFloor = true;
    }
    return 1;
    }
    return 0;
}

int Tetrimono::moveLeft() {
    if (Grid::isInBounds(getLeftBound()-25,coord.x2) && !onFloor) {
    coord.x1 -= 25;
    return 1;
    }
    return 0;
}

int Tetrimono::moveRight() {
    if (Grid::isInBounds(getRightBound()+25,coord.x2) && !onFloor){
    coord.x1 += 25;
    return 1;
    }
    return 0;
}

