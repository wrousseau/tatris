#ifndef GRID_H
#define GRID_H
#include "Structures.h"
#include "qpainter.h"

class Tetrimono;

enum
{
    GRID_HEIGHT = 22,
    GRID_WIDTH = 10

};

class Grid {

private :
    blockColor area[GRID_HEIGHT][GRID_WIDTH]; // représente la grille des élements fixés
    int highest;

public:
    Grid();
    ~Grid();
    bool isFree(point par1);
    bool isInBounds(int par1, int par2);
    bool isNotOccupied(point par1);
    bool isLineFull(int line);
    void fillGrid(Tetrimono* par1Tetrimono);//complète la grille avec le tetrimono envoyé, supposé tombé au sol ou sur une pièce
    blockColor getValues(int i, int j);//renvoie le type de bloc en i,j. Egal à EMPTY si vide
    int getHighest();
    void setHighest(int par1);
    void deleteLine(int i);//supprime une ligne et décale les lignes d'au dessus vers le bas

};

#endif // GRID_H
