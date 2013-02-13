#include "Game.h"

Game::Game(Grid* par1Grid) {
    grid = par1Grid;
    gameOn = true;
    level = 0;
    score = 0;
    deletedLines = 0;
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

int Game::getScore() {
    return score;
}

void Game::addToScore(int par1) {
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
    {
        return;
    }
    else if(bonus == 1){// on supprime depuis le haut donc pas besoin de s'inquiéter d'un décalage
        score+=40*(level+1);
        grid->deleteLine(tab[0]);
        deletedLines++;
    }
    else if(bonus == 2)
    {
        score+=100*(level+1);
        grid->deleteLine(tab[0]);
        grid->deleteLine(tab[1]);
        deletedLines+=2;
    }
    else if(bonus == 3)
    {
        score+=300*(level+1);
        grid->deleteLine(tab[0]);
        grid->deleteLine(tab[1]);
        grid->deleteLine(tab[2]);
        deletedLines+=3;
    }
    else if(bonus == 4)
    {
        score+=1200*(level+1);
        grid->deleteLine(tab[0]);
        grid->deleteLine(tab[1]);
        grid->deleteLine(tab[2]);
        grid->deleteLine(tab[3]);
        deletedLines+=4;
    }

    emit updateScore(score);
    checkScore();
    return;
}

void Game::checkScore() {
        if (deletedLines >= 1*(level+1))
        {
            level++;
            QString str = "Niveau " + QString::number(level);
            emit updateLevel(str);
        }

}
