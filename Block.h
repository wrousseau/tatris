#ifndef BLOCK_H
#define BLOCK_H
#include "Structures.h"

class Block
{
private:
    point coord;
    double speed;
    int couleur;

public:
    Block(point spread) {
        coord.x1 = rand(spread.x1,TAILLEGRILLE-(spred.x2));
        coord.x2 = 0;
    }

    Block()
};

#endif // BLOCK_H
