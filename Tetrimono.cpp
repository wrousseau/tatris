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
    setColor();
}

Tetrimono::~Tetrimono() {
}

void Tetrimono::initializeValues(int par1, int par2) {
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

bool Tetrimono::isTouchingBlockDown()
{
    short i, x, y;
    for(int j = 0; j < 5 ; j++) //on regarde pour chaque colonne de values
    {
        i = getColumnLowestEl(j);
        if(i != -1)// si la colonne n'est pas vide
        {
            y =  (coord.x2)/25 + i;
            x =  (coord.x1)/25 + j;

            if(grid->getValues(y+1, x) != EMPTY)//si ya un truc en dessous
                return true;
        }

    }
    return false;
}

bool Tetrimono::isTouchingBlockLeft()
{
    short j, x, y;
    for(int i = 0; i < 5 ; i++) //on regarde pour chaque ligne de values
    {
        j = getLineLeftestEl(i);
        if(j != -1)// si la colonne n'est pas vide
        {
            y =  (coord.x2)/25 + i;
            x =  (coord.x1)/25 + j;

            if(grid->getValues(y, x-1) != EMPTY)//si ya un truc à gauche
                return true;
        }

    }
    return false;
}

bool Tetrimono::isTouchingBlockRight()
{
    short j, x, y;
    for(int i = 0; i < 5 ; i++) //on regarde pour chaque ligne de values
    {
        j = getLineRightestEl(i);
        if(j != -1)// si la colonne n'est pas vide
        {
            y =  (coord.x2)/25 + i;
            x =  (coord.x1)/25 + j;

            if(grid->getValues(y, x+1) != EMPTY)//si ya un truc à droite
                return true;
        }

    }
    return false;
}

blockColor Tetrimono::getColor(){
    return color;
}

short Tetrimono::getValues(int i, int j){
    return values[i][j];
}

int Tetrimono::getX() {
    return coord.x1;
}

int Tetrimono::getLeftBound() {

    short tmp = 4;
    for(int i=0 ; i < 5 ; i++) // on récupère la position de l'élément le plus à gauche
    {
        short j = getLineLeftestEl(i);

        if(j >= 0 && j < tmp)
            tmp = j;
    }
    return (coord.x1 + tmp*25);

}

int Tetrimono::getRightBound() {

    short tmp = 0;
    for(int i=0 ; i < 5 ; i++) //cf getLeftBound()
    {
        short j = getLineRightestEl(i);
        if(j >= 0 && j > tmp)
            tmp = j;
    }
    return (coord.x1 + tmp*25);

}

int Tetrimono::getUpperBound() {
    short tmp = 0;
    for(int j=0 ; j < 5 ; j++)
    {
        short i = getColumnLowestEl(j);
        if(i >= 0 && i < tmp)
            tmp = i;
    }
    return (coord.x2 +tmp*25);
}

int Tetrimono::getLowerBound() {

    short tmp = 0;
    for(int j=0 ; j < 5 ; j++)
    {
        short i = getColumnLowestEl(j);
        if(i >= 0 && i > tmp)
            tmp = i;
    }
    return (coord.x2 +tmp*25); //le rajout des 25 se fait dans fall()
}

int Tetrimono::getY() {
    return coord.x2;
}

short Tetrimono::getColumnLowestEl(int j)
{
    short i=0;
    bool empty = true;
    for(int k=0 ; k < 5 ; k++)
    {
        if(values[k][j] != 0)
        {
            i = k;
            empty = false;
        }
    }
    if(empty)
        i = -1;
    return i; // si -1 -> pas d'élément sur la colonne par construction de values
}

short Tetrimono::getLineLeftestEl(int i)
{
    short j=0;
    bool empty = true;
    for(int k=4 ; k >= 0 ; k--)
    {
        if(values[i][k] != 0)
        {
            j = k;
            empty = false;
        }
    }
    if(empty)
        j = -1;
    return j; // si -1 -> pas d'élément sur la colonne par construction de values
}

short Tetrimono::getLineRightestEl(int i)
{
    short j=0;
    bool empty = true;
    for(int k=0 ; k < 5 ; k++)
    {
        if(values[i][k] != 0)
        {
            j = k;
            empty = false;
        }
    }
    if(empty)
        j = -1;
    return j; // si -1 -> pas d'élément sur la colonne par construction de values
}

void Tetrimono::setX(int par1) {
    coord.x1 = par1;
}

void Tetrimono::setY(int par1) {

    coord.x2 = par1;
}

void Tetrimono::setColor(){

    if(blockType==0){
        color = YELLOW;
    }
    else if(blockType==1){
        color = CYAN;
    }
    else if(blockType==2){
        color = RED;
    }
    else if(blockType==3){
        color = GREEN;
    }
    else if(blockType==4){
        color = ORANGE;
    }
    else if(blockType==5){
        color = PURPLE;
    }
    else if(blockType==6){
        color = BLUE;
    }
    else
        color = RED;

    return;
}

int Tetrimono::fall(int par1) {
    qDebug() << grid->isInBounds(getLeftBound() ,getLowerBound()+par1);
    if (grid->isInBounds(getLeftBound(),getLowerBound()+par1) && !isTouchingBlockDown()) {
        coord.x2 += par1;
        return 1;
    }
    if (!onFloor) {
        onFloor = true;
        grid->fillGrid(this);
        grid->setHighest(grid->getHighest() - (125 - farthests[3] - farthests[2])/25);
    }
    return 0;
}

int Tetrimono::moveLeft() {

    if (grid->isInBounds(getLeftBound()-25, coord.x2) && !onFloor && !isTouchingBlockLeft()) {
        coord.x1 -= 25;
        return 1;
    }
    return 0;
}

int Tetrimono::moveRight() {

    if (grid->isInBounds(getRightBound()+25, coord.x2) && !onFloor && !isTouchingBlockRight()){
        coord.x1 += 25;
        return 1;
    }
    return 0;
}

