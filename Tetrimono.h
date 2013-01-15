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
    int numberOfBlocks;
    point spread;
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
        Block firstBlock = new Block(spread);
        blockVector.push_back(*firstBlock);
        for (int i = 1; i < numberOfBlocks; i++) {
            blockVector.push_back(Block())
        }

    }
};

#endif // TETRIMONO_H
