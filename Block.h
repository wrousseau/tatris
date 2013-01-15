#ifndef BLOCK_H
#define BLOCK_H
#include "Structures.h"
#include "Grille.h"

class Block
{
private:
    point coord;
    double speed;
    int couleur;

public:
    Block(point coord, int color, bool isRand = false) {
        if (isRand) {
        coord.x1 = rand(coord.x1,LARGEUR_GRILLE-(coord.x2));
        coord.x2 = 0;
        }
        else {
            coord.x1 = spread.x1;
            coord.x2 = spread.x2;
        }
        couleur = color;
        //speed = 1 + Game->getLevel()/10;
    }

    int getCouleur(){
        return couleur;
    }

    point getPosition() {
        return coord;
    }

    double getSpeed() {
        return speed;
    }

    void setCouleur(int par1) {
        if (i <= 7 && i >=0) {
            couleur = par1;
        }
    }

    int setCoord(point par1) {
        coord = coord;
    }

    int moveBlock(int par1, int par2) {
        point target = coord;
        target.x1 += par1;
        target.x2 += par2;
        if ((par1 == 1 || par1 == -1 || par2 == -1) && Grille.isFree(target)) {
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
