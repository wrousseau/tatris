/*!
 * \file Tetrimono.cpp
 * \brief Jeu TAtris basé sur Tétris
 * \author Simon MANCHEL, Woody ROUSSEAU
 * \version 1.0
 */

#include "Tetrimono.h"
#include "Grid.h"
#include "unistd.h"


Tetrimono::Tetrimono(int par1, Grid* par2Grid) {
    onFloor = false;
    moveTry = 0;
    rotation = 0;
    grid = par2Grid;
    blockType = par1;
    farthests[0] = 125;// par défaut on le met à 5 cases (125px)
    farthests[1] = 125;
    farthests[2] = 125;
    farthests[3] = 125;
    initializeValues(par1, 0);
    coord.x1=((GRID_WIDTH)*25/2 - 25)-farthests[0];
    coord.x2=-farthests[2];
    setColor();
    rotateSound = new QMediaPlayer;
    rotateSound->setMedia(QUrl::fromLocalFile(globalPath + "rotate.mp3"));
    rotateSound->setVolume(50);
    if (!areSoundsOn)
    {
        rotateSound->setVolume(0);
    }
    fallSound = new QMediaPlayer;
    fallSound->setMedia(QUrl::fromLocalFile(globalPath + "fall.mp3"));
    fallSound->setVolume(50);
    if (!areSoundsOn)
    {
        fallSound->setVolume(0);
    }
}

Tetrimono::~Tetrimono()
{
    #ifdef Q_OS_WIN32
    delete fallSound;
    delete rotateSound;
    #endif
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
    int tmp;

    tmp = getLeftBound();
    if(tmp < 0)// si on arrive trop à gauche on décale à droite
        coord.x1 -= tmp;

    tmp = getRightBound();
    if(tmp > (GRID_WIDTH - 1)*25) //si on arrive trop à droite on décale à gauche
        coord.x1 -= (tmp - (GRID_WIDTH - 1)*25);

    tmp = getLowerBound();
    if(tmp > (GRID_HEIGHT - 1)*25) //si on arrive trop en bas ...
        coord.x2 -= (tmp - (GRID_HEIGHT - 1)*25);

    //Vérification : la rotation amène-t-elle le tetrimono au dessus d'un block déjà posé ?
    bool merging = false;

    for(int i = 0 ; i < 5 ; i++)
    {
        for(int j = 0 ; j < 5 ; j++)
        {
            if((values[i][j] != 0) && (grid->getValues(i+(coord.x2/25), j+(coord.x1/25)) != EMPTY))//Si une case du tetrimono chevauche avec un block non vide de la grille
                merging = true;
            if(coord.x2 < 0)
                merging = false;

        }
    }
    if(merging)//s'il y a chevauchement on annule la rotation
    {
        rotation -= 1;
        rotation %= 4;
        initializeValues(blockType, rotation);
    }
    else {
        rotateSound->stop();
        rotateSound->play();
    }
    return;
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

bool Tetrimono::allowedToMove(unsigned level){

    if(moveTry < ((float)27 / (level + 4.5)))
    {
        moveTry++;
        return true;
    }
    else
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
        color = PURPLE;
    }
    else if(blockType==5){
        color = ORANGE;
    }
    else if(blockType==6){
        color = BLUE;
    }
    else
        color = RED;

    return;
}

int Tetrimono::fall(int par1) {
    moveTry = 0;
    if (grid->isInBounds(getLeftBound(),getLowerBound()+par1) && !isTouchingBlockDown()) {
        coord.x2 += par1;
        return 1;
    }
    if (!onFloor) {
        onFloor = true;
        fallSound->stop();
        fallSound->play();
        sleep(1.2); //Si on enlève le sleep, le son n'est joué que quand on maintient la flèche du bas (sous Laptop Simon, Windows)
        grid->fillGrid(this);
        grid->setHighest(grid->getHighest() - (125 - farthests[3] - farthests[2])/25);
    }
    return 0;
}

int Tetrimono::moveLeft(unsigned level) {

    if (grid->isInBounds(getLeftBound()-25, coord.x2) && !onFloor && ((!isTouchingBlockLeft() || coord.x2 < 50)) && allowedToMove(level))   {
        coord.x1 -= 25;
        return 1;
    }
    return 0;
}

int Tetrimono::moveRight(unsigned level) {

    if (grid->isInBounds(getRightBound()+25, coord.x2) && !onFloor && ((!isTouchingBlockRight() || coord.x2 <50)) && allowedToMove(level)) {
        coord.x1 += 25;
        return 1;
    }
    return 0;
}

