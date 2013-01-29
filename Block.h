/*#ifndef BLOCK_H
#define BLOCK_H
#include "Structures.h"
#include "Grid.h"

class Block
{
private:
    point coord;
    double speed;
    color couleur;

public:
    Block(point coord, color colorSet, bool isRand = false) {
        if (isRand) {
        //coord.x1 = rand(coord.x1,Grid::GRID_WIDTH-(coord.x2));
        coord.x2 = 0;
        }
        else {
        }
        couleur = color;
        speed = 1 + (double)(Game->getLevel()/10);

    }

    color getCouleur(){
        return couleur;
    }

    point getPosition() {
        return coord;
    }

    double getSpeed() {
        return speed;
    }

    void setCouleur(color par1) {
            couleur = par1;
    }

    int setCoord(point par1) {
        coord = par1;
    }

    bool isBlockMovable(int par1, int par2, Grille* grille){
        point target = coord;
        target.x1 += par1;
        target.x2 += par2;
        if ((par1 == 1 || par1 == -1 || par2 == -1) && grille->isFree(target))
            return true;
        else
            return false;
    }

    int moveBlock(int par1, int par2, Grille* grille) {
        point target = coord;
        target.x1 += par1;
        target.x2 += par2;
        if ((par1 == 1 || par1 == -1 || par2 == -1) && grille->isFree(target)) {
            coord.x1 = target.x1;
            coord.x2 = target.x2;
            return 1;
        }
        else {
            return 0;
        }
    }

};

#endif // BLOCK_H
*/
