#ifndef PARTIE_H
#define PARTIE_H


class Game {

private:
    unsigned level;
    unsigned long int score;
    bool gameOn;


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
};

#endif // PARTIE_H
