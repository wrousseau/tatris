#ifndef TETRIMONO_H
#define TETRIMONO_H

#include "Structures.h"
#include <vector>
#include "Block.h"

class Tetrimono
{
   protected:

    int rotation;
    bool isOnScreen, isOnFloor;
    int numberOfBlocks;
    point spread;
    vector<Block> blockVector;


public:

    virtual void initializeBlocks();

};

class SquareTetrimono: public Tetrimono
{
private:

public:
    SquareTetrimono() {
        numberOfBlock = 4;
        spread.x1 = 0;
        spread.x2 = 1;
        initializeBlocks();
    }



    virtual void initializeBlocks() {
        Block firstBlock = new Block(spread);
        blockVector.push_back(*firstBlock);
        for (int i = 1; i < numberOfBlocks; i++) {
            blockVector.push_back(Block())
        }

    }
};

#endif // TETRIMONO_H
