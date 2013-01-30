#ifndef STRUCTURES_H
#define STRUCTURES_H


typedef struct
         {
          int x1;
          int x2;
         } point;

static char valuesEnumeration[3][4][5][5] =
{
    {
        {
            {0,0,0,0,0},//Toutes les positions de rotation du carré
            {0,0,0,0,0},
            {0,0,2,1,0},
            {0,0,1,1,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,2,1,0},
            {0,0,1,1,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,2,1,0},
            {0,0,1,1,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,2,1,0},
            {0,0,1,1,0},
            {0,0,0,0,0}
        }
    },
    {
        {
            {0,0,0,0,0},//toutes les positions de rotation de la barre droite
            {0,0,0,0,0},
            {1,1,2,1,0},
            {0,0,0,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,1,0,0},
            {0,0,1,0,0},
            {0,0,2,0,0},
            {0,0,1,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,1,2,1,1},
            {0,0,0,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,1,0,0},
            {0,0,2,0,0},
            {0,0,1,0,0},
            {0,0,1,0,0}
        }
    },
    {
        {
            {0,0,0,0,0},//toutes les positions de rotation de la barre droite
            {0,0,0,1,0},
            {0,1,2,1,0},
            {0,1,0,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,1,1,0,0},
            {0,0,2,0,0},
            {0,0,1,1,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,0,1,0},
            {0,1,2,1,0},
            {0,1,0,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,1,1,0,0},
            {0,0,2,0,0},
            {0,0,1,1,0},
            {0,0,0,0,0}
        }
    },
};

typedef enum{
    EMPTY, RED, YELLOW, GREEN, BLUE, PURPLE, BROWN, WHITE
} blockColor;


#endif // STRUCTURES_H
