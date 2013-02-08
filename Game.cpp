#include "Game.h"

Game::Game() {
    gameOn = true;
    level = 1;
    score = 0;
}

Game::~Game() {}

unsigned Game::getLevel() {
    return level;
}

void Game::setLevel(unsigned par1) {
    if (par1 > 0) {
    level = par1;
    }
}

void Game::levelUp(){
    level++;
}

unsigned long int Game::getScore() {
    return score;
}

void Game::addToScore(unsigned long int par1) {
    score += par1;
}

int Game::gameOver() {
    gameOn = false;
    return score;
}

bool Game::isGameOn() {
    return gameOn;
}

void Game::setGrid(Grid* parGrid){
    grid = parGrid;
}

void Game::scoreManage(){

    int bonus = 0;
    int tab[4]={0};

    for(int i=0; i < GRID_HEIGHT ; i++){ //on met dans bonus le nombres de lignes complètes, et on stocke les lignes dans tab

        if(grid->isLineFull(i))
        {
            tab[bonus] = i;
            bonus++;
        }
    }

    if(bonus == 0)
        return;
    else if(bonus == 1){// on supprime depuis le haut donc pas besoin de s'inquiéter d'un décalage
        score+=40;
        grid->deleteLine(tab[0]);
    }
    else if(bonus == 2)
    {
        score+=100;
        grid->deleteLine(tab[0]);
        grid->deleteLine(tab[1]);
    }
    else if(bonus == 3)
    {
        score+=300;
        grid->deleteLine(tab[0]);
        grid->deleteLine(tab[1]);
        grid->deleteLine(tab[2]);
    }
    else if(bonus == 4)
    {
        score+=1200;
        grid->deleteLine(tab[0]);
        grid->deleteLine(tab[1]);
        grid->deleteLine(tab[2]);
        grid->deleteLine(tab[3]);
    }

    return;
}
