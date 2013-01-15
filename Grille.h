#ifndef GRILLE_H
#define GRILLE_H
#include "Constantes.h"
#include "Structures.h"

const int HAUTEUR_GRILLE = 22;
const int LARGEUR_GRILLE = 10;


class Grille{

private :

    int area[LARGEUR_GRILLE][HAUTEUR_GRILLE] = {{0}};

public:

    bool isFree(point par1)
    {
        if (isInBounds(par1) && isNotOccupied(par1)) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isInBounds(par1) {
        if (par1.x1 <= LARGEUR_GRILLE && par1.x1 >= 0 && par1.x2 <= HAUTEUR_GRILLE && par1.x2 >= 0) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isNotOccupied(par1) {

    }


};

#endif // GRILLE_H
