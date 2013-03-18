#ifndef GRID_H
#define GRID_H

/*!
 * \file Grid.h
 * \brief Jeu TAtris basé sur Tétris
 * \author Simon MANCHEL, Woody ROUSSEAU
 * \version 1.0
 */


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
    /*!
     *  \brief Constructeur Grille
     */
    Grid();
    /*!
     *  \brief Destructeur Grille
     */
    ~Grid();
    /*!
     *  \brief Test d'accessibilité du bloc
     *  \param par1 : coordonnées du point à tester sur la grille (*25 pixels)
     *  \return Faux si le point est hors grille ou occupé par un bloc non vide, Vrai sinon
     */
    bool isFree(point par1);
    /*!
     *  \brief Test de placement du bloc
     *
     *
     *  \param par1 : coordonnées du bloc à tester sur la grille (*25 pixels)
     *  \return Vrai si le bloc existe sur la grille, Faux sinon
     */
    bool isInBounds(int par1, int par2);
    /*!
     *  \brief Test d'occupation du bloc
     *  \param par1 : coordonnées du bloc à tester sur la grille (*25 pixels)
     *  \return Vrai si le bloc est vide, Faux sinon.
     */
    bool isNotOccupied(point par1);
    /*!
     *  \brief Test de complétude d'une ligne
     *  \param line : numéro de la ligne : de 0(en haut de la grille) à GRID_HEIGHT-1
     *  \return Vrai si la ligne est complète, Faux sinon.
     */
    bool isLineFull(int line);
    /*!
     *  \brief Remplissage de la grille
     *
     *  Met à jour la grille avec un nouveau Tétrimono tombé au sol ou sur un objet
     *  \param par1Tetrimono : Pointeur vers le Tétrimono en train de tomber
     */
    void fillGrid(Tetrimono* par1Tetrimono);
    /*!
     *  \brief Accesseur bloc
     *
     *  Renvoi le type de bloc (couleur) en i,j
     *  \param i : ligne de 0(en haut) à GRID_HEIGHT - 1
     *  j : colonne de 0 (à gauche) à GRID_WIDTH -1
     *  \return la couleur du bloc, sous l'énumération blockColor. Egal à EMPTY si vide
     */
    blockColor getValues(int i, int j);//renvoie le type de bloc en i,j. Egal à EMPTY si vide
    /*!
     *  \brief Accesseur Highest
     *  \return colonne de l'élément le plus haut
     */
    int getHighest();
    /*!
     *  \brief Mutateur Highest
     *  \param par1 : colonne de l'élément le plus haut
     */
    void setHighest(int par1);
    /*!
     *  \brief Suppression d'une ligne
     *
     *  Supprime une ligne et décale les lignes d'au dessus vers le bas
     *  \param i : numéro de la ligne (0 en haut)
     */
    void deleteLine(int i);

};

#endif // GRID_H
