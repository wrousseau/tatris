#ifndef PARTIE_H
#define PARTIE_H

#include "Grid.h"


class Game {

private:
    unsigned level;
    unsigned long int score;
    bool gameOn;
    Grid* grid;


public:
    Game();
    ~Game();
    unsigned getLevel();
    void setLevel(unsigned par1);
    void levelUp();
    unsigned long int getScore();
    void addToScore(unsigned long int par1);
    int gameOver();
    bool isGameOn();
    void setGrid(Grid* parGrid);
    void scoreManage(); //gère les suppressions de lignes et le score

};

#endif // PARTIE_H
