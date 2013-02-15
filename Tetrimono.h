#ifndef TETRIMONO_H
#define TETRIMONO_H

#include "Structures.h"
#include "Grid.h"
#include <QMediaPlayer>


class Tetrimono // Représente le symbole en train de tomber
{
    protected:
        point coord;
        int blockType;
        blockColor color;
        int rotation;
        bool onScreen, onFloor;
        Grid* grid;
        int farthests[4]; // left, right, up, down || représente la distance de vide minimale dans chaque direction
        short values[5][5]; // représente la matrice du Tétrimono qui tombe, elle peut prendre 4 valeurs en fonction de la rotation
        QMediaPlayer* rotateSound;
        QMediaPlayer* fallSound;



    public:
        Tetrimono(int par1, Grid* par2Grid);
        void initializeValues(int par1, int par2);// initialise values et farthests
        short getValues(int i, int j); //retourne values[i][j]
        void rotate();
        bool isOnScreen();
        bool isOnFloor();
        bool isTouchingBlockDown();
        bool isTouchingBlockLeft();
        bool isTouchingBlockRight();
        blockColor getColor();
        int getX();
        int getLeftBound();
        int getRightBound();
        int getUpperBound();
        int getLowerBound();
        int getY();
        short getColumnLowestEl(int j);
        short getLineLeftestEl(int i);
        short getLineRightestEl(int i);
        void setX(int par1);
        void setY(int par1);
        void setColor();
        int fall(int par1);
        int moveLeft();
        int moveRight();
        ~Tetrimono();

};






#endif // TETRIMONO_H
