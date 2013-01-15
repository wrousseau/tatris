#ifndef PARTIE_H
#define PARTIE_H


class Partie {

private:
    unsigned niveau;
    unsigned long int score;
    bool isGameOn;


public:

    Partie() {
        isGameOn = true;
        niveau = 1;
        score = 0;
    }

    ~Partie() {}

    unsigned getLevel() {
        return niveau;
    }

    void setLevel(unsigned par1) {
        if (par1 > 0) {
        niveau = par1;
        }
    }

    void levelUp(){
        niveau++;
    }

    unsigned long int getScore() {
        return score;
    }

    void addToScore(unsigned long int par1) {
        score += par1;
    }

    int gameOver() {
        isGameOn = false;
        return score;
    }
};

#endif // PARTIE_H
