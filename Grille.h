#ifndef GRILLE_H
#define GRILLE_H
#include "Constantes.h"
#include "Structures.h"
#include "Block.h"



class Grille{

private :

    color area[LARGEUR_GRILLE][HAUTEUR_GRILLE];

public:

    Grille(){
        int i=0,j=0;
        for(i=0 ; i<LARGEUR_GRILLE ; i++)
        {
            for(j=0 ; j<HAUTEUR_GRILLE ; j++)
            {
                area[i][j]=EMPTY;
            }
        }
    }


    bool isFree(point par1)
    {
        if (isInBounds(par1) && isNotOccupied(par1)) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isInBounds(point par1) {
        if (par1.x1 <= LARGEUR_GRILLE && par1.x1 >= 0 && par1.x2 <= HAUTEUR_GRILLE && par1.x2 >= 0) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isNotOccupied(point par1) {
        if(area[par1.x1][par1.x2] == EMPTY)
            return true;
        else
            return false;
    }

    bool isLineFull(int line){
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


};

#endif // GRILLE_H
