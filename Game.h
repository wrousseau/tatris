#ifndef PARTIE_H
#define PARTIE_H


class Game {

private:
    unsigned level;
    unsigned long int score;
    bool gameOn;


public:

    Game() {
        gameOn = true;
        level = 1;
        score = 0;
    }

    ~Game() {}

    unsigned getLevel() {
        return level;
    }

    void setLevel(unsigned par1) {
        if (par1 > 0) {
        level = par1;
        }
    }

    void levelUp(){
        level++;
    }

    unsigned long int getScore() {
        return score;
    }

    void addToScore(unsigned long int par1) {
        score += par1;
    }

    int gameOver() {
        gameOn = false;
        return score;
    }

    bool isGameOn() {
        return gameOn;
    }
};

#endif // PARTIE_H
