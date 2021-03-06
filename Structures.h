#ifndef STRUCTURES_H
#define STRUCTURES_H

/*!
 * \file Structures.h
 * \brief Jeu TAtris basé sur Tétris
 * \author Simon MANCHEL, Woody ROUSSEAU
 * \version 1.0
 */

/**
 * \struct point
 * \brief Coordonnées d'un point
 *
 * Coordonnées d'un Tétrimono. S'incrément par 25 (blocs de 25 pixels)
 */
typedef struct
         {
          int x1;
          int x2;
         } point;

// valuesEnumeration représentes toutes les position possibles de chaque tétrimono
//on l'appelle de la sorte : valuesEnumeration[typeTetrimono][configuration_rotation][ligne][colonne]
static const short valuesEnumeration[7][4][5][5] =
{
    {
        {
            {0,0,0,0,0},//Toutes les positions de rotation du carré - O Tétrimono
            {0,0,0,0,0},
            {0,0,1,1,0},
            {0,0,1,1,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,1,1,0},
            {0,0,1,1,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,1,1,0},
            {0,0,1,1,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,1,1,0},
            {0,0,1,1,0},
            {0,0,0,0,0}
        }
    },
    {
        {
            {0,0,0,0,0},//toutes les positions de rotation de la barre droite - I tétrimono
            {0,0,0,0,0},
            {1,1,1,1,0},
            {0,0,0,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,1,0,0},
            {0,0,1,0,0},
            {0,0,1,0,0},
            {0,0,1,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,1,1,1,1},
            {0,0,0,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,1,0,0},
            {0,0,1,0,0},
            {0,0,1,0,0},
            {0,0,1,0,0}
        }
    },
    {
        {
            {0,0,0,0,0},//toutes les positions de rotation de la pièce en biais - Z Tétrimono
            {0,0,0,1,0},
            {0,0,1,1,0},
            {0,0,1,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,1,1,0,0},
            {0,0,1,1,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,1,0,0},
            {0,1,1,0,0},
            {0,1,0,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,1,1,0,0},
            {0,0,1,1,0},
            {0,0,0,0,0},
            {0,0,0,0,0}
        }
    },
    {
        {
            {0,0,0,0,0},//toutes les positions de rotation de la pièce en biais inversé- S Tétrimono
            {0,0,1,0,0},
            {0,0,1,1,0},
            {0,0,0,1,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,1,1,0},
            {0,1,1,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,1,0,0,0},
            {0,1,1,0,0},
            {0,0,1,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,1,1,0},
            {0,1,1,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0}
        }
    },
    {
        {
            {0,0,0,0,0},//toutes les positions de rotation de la pièce en T - T Tétrimono
            {0,1,1,1,0},
            {0,0,1,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,1,0,0},
            {0,1,1,0,0},
            {0,0,1,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,1,0,0},
            {0,1,1,1,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,1,0,0},
            {0,0,1,1,0},
            {0,0,1,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0}
        }
    },
    {
        {
            {0,0,0,0,0},//toutes les positions de rotation de la pièce en L - L Tétrimono
            {0,0,0,0,0},
            {0,1,1,1,0},
            {0,1,0,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,1,1,0,0},
            {0,0,1,0,0},
            {0,0,1,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,0,1,0},
            {0,1,1,1,0},
            {0,0,0,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,1,0,0},
            {0,0,1,0,0},
            {0,0,1,1,0},
            {0,0,0,0,0}
        }
    },
    {
        {
            {0,0,0,0,0},//toutes les positions de rotation de la pièce en L inversé- J Tétrimono
            {0,0,0,0,0},
            {0,1,1,1,0},
            {0,0,0,1,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,1,0,0},
            {0,0,1,0,0},
            {0,1,1,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,1,0,0,0},
            {0,1,1,1,0},
            {0,0,0,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,1,1,0},
            {0,0,1,0,0},
            {0,0,1,0,0},
            {0,0,0,0,0}
        }
    },
};

typedef enum{
    EMPTY, RED, YELLOW, GREEN, BLUE, PURPLE, BROWN, ORANGE, CYAN
} blockColor;


#endif // STRUCTURES_H
