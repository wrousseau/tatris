#ifndef TETRIMONO_H
#define TETRIMONO_H

#include "Structures.h"
#include <vector>
#include "Block.h"

class Tetrimono
{
   protected:

    int inclinaison;
    bool isOnScreen, isOnFloor;
    virtual int numberOfBlocks;
    virtual point spread;
    vector<Block> blockVector;

public:

    virtual void initializeBlocks();

};

class TetrimonoCarre: public Tetrimono
{
private:

public:
    TetrimonoCarre() {
        numberOfBlock = 4;
        spread.x1 = 0;
        spread.x2 = 1;
        initializeBlocks();
    }



    virtual void initializeBlocks() {
        Block firstBlock = new Block();
    }
};

#endif // TETRIMONO_H
