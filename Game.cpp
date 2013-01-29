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
