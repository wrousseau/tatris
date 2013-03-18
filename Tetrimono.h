#ifndef TETRIMONO_H
#define TETRIMONO_H

#include "Structures.h"
#include "Grid.h"
#include <QMediaPlayer>
#include <QDir>

extern QString globalPath;
extern bool isMusicOn;
extern bool areSoundsOn;

class Tetrimono // Représente le symbole en train de tomber
{
    private:
        point coord;
        int blockType;
        blockColor color;// ENUM définie dans structures.h
        short moveTry; //nombre de tentatives d'aller à gauche ou à droite depuis le dernier fall
        int rotation; //donne l'angle de la pièce (0<=> 0°, 3<=> 270°)
        bool onScreen, onFloor;
        Grid* grid;
        int farthests[4]; // left, right, up, down || représente la distance de vide minimale dans chaque direction
        short values[5][5]; // représente la matrice du Tétrimono qui tombe, elle peut prendre 4 valeurs en fonction de la rotation (0 = case vide, 1 = case pleine)
    public:
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
        bool allowedToMove(unsigned level);
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
        int moveLeft(unsigned level);
        int moveRight(unsigned level);
        ~Tetrimono();

};






#endif // TETRIMONO_H
