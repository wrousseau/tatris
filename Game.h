#ifndef PARTIE_H
#define PARTIE_H

#include "Grid.h"
#include <QMediaPlayer>
#include <QObject>

extern QString globalPath;

class Game: public QObject {

    Q_OBJECT

private:
    unsigned level;
    int score;
    unsigned deletedLines;
    bool gameOn;
    Grid* grid;
    QMediaPlayer *oneLineSound;
    QMediaPlayer *fourLinesSound;

signals:
    void updateScore(int i);
    void updateLevel(QString par1);


public:
    Game(Grid* par1Grid);
    ~Game();
    unsigned getLevel();
    void setLevel(unsigned par1);
    void levelUp();
    int getScore();
    void addToScore(int par1);
    int gameOver();
    bool isGameOn();
    void setGrid(Grid* parGrid);
    void scoreManage(); //gère les suppressions de lignes et le score
    void checkScore(); // Gère le Passage au Niveau Supérieur

};

#endif // PARTIE_H
