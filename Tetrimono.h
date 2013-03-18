#ifndef TETRIMONO_H
#define TETRIMONO_H

/*!
 * \file Tetrimono.h
 * \brief Jeu TAtris basé sur Tétris
 * \author Simon MANCHEL, Woody ROUSSEAU
 * \version 1.0
 */


#include "Structures.h"
#include "Grid.h"
#include <QMediaPlayer>
#include <QDir>

extern QString globalPath;


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
        QMediaPlayer* rotateSound;
        QMediaPlayer* fallSound;



    public:/*!
     *  \brief Constructeur Tétrimono
     *  \param par1 : Type de Tétrimono
     *  par2Grid : Pointeur vers la grille utilisée
     */
        Tetrimono(int par1, Grid* par2Grid);
        /*!
         *  \brief Initialise la matrice du Tétrimono
         *  \param par1 : Type de Tétrimono
         *  par2 : Angle Rotation
         */
        void initializeValues(int par1, int par2);// initialise values et farthests
        /*!
         *  \brief Retourne l'élément de la matrice du Tétrimono à la position i,j
         *  \return 0 : Pas de bloc, 1:Bloc
         */
        short getValues(int i, int j); //retourne values[i][j]
        /*!
         *  \brief Effectue une rotation horaire de la matrice du Tétrimono
         */
        void rotate();
        /*!
         *  \brief Test de présence sur l'écran
         *  \return Vrai si le Tétrimono est sur l'écran, Faux sinon
         */
        bool isOnScreen();
        /*!
         *  \brief Test de contact avec le sol
         *  \return Vrai si le Tétrimono touche le sol ou un autre bloc verticalement, Faux sinon
         */
        bool isOnFloor();
        /*!
         *  \brief Test en bas
         *  \return Vrau si il touche un bloc en bas
         */
        bool isTouchingBlockDown();
        /*!
         *  \brief Test gauche
         *  \return Vrai si il touche un bloc à gauche
         */
        bool isTouchingBlockLeft();
        /*!
         *  \brief Test droite
         *  \return Vrai si il touche un bloc à droite
         */
        bool isTouchingBlockRight();
        /*!
         *  \brief Autorisation de bouger
         *
         *  Regarde le nombre de tentative de bouger déjà faite et donne ou non la permission selon le niveau
         *  \param level : Niveau de la partie
         *  \return Vrai si la permission est accordée
         */
        bool allowedToMove(unsigned level);
        /*!
         *  \brief Retourne la couleur du Tétrimono
         */
        blockColor getColor();
        /*!
         *  \brief Retourn l'abcisse du Tétrimono (*25 pixels)
         */
        int getX();
        /*!
         *  \brief Retourne la marge à gauche du Tétrimono (*25pixels)
         */
        int getLeftBound();
        /*!
         *  \brief Retourne la marge à droite du Tétrimono (*25pixels)
         */
        int getRightBound();
        /*!
         *  \brief Retourne la marge haute du Tétrimono (*25pixels)
         */
        int getUpperBound();
        /*!
         *  \brief Retourne la marge basse du Tétrimono (*25pixels)
         */
        int getLowerBound();
        /*!
         *  \brief Retourne l'ordonnée du Tétrimono (*25pixels)
         */
        int getY();
        /*!
         *  \brief Element le plus bas
         *  \param j : colonne à tester
         *  \return la ligne de l'élement le plus bas
         */
        short getColumnLowestEl(int j);
        /*!
         *  \brief Element le plus à gauche
         *  \param i : ligne à tester
         *  \return la colonne de l'élément le plus à gauche
         */
        short getLineLeftestEl(int i);
        /*!
         *  \brief Element le plus à droite
         *  \param i : ligne à tester
         *  \return la colonne de l'élément le plus à droite
         */
        short getLineRightestEl(int i);
        /*!
         *  \brief Mutateur abcisse
         *  \param par1 : abcisse(*25pixels)
         */
        void setX(int par1);
        /*!
         *  \brief Mutateur ordonnée
         *  \param par1 : ordonnée(*25pixels)
         */
        void setY(int par1);
        /*!
         *  \brief Mutateur couleur
         *
         *  Automatique en fonction du type de Tétrimono
         */
        void setColor();
        /*!
         *  \brief Chute du Tétrimono
         *  \param par1 : nombre de pixels de chute (25 par défaut)
         *  \return
         */
        int fall(int par1 = 25);
        /*!
         *  \brief Tentative de déplacement à gauche
         *  \param level : Niveau de la partie
         */
        int moveLeft(unsigned level);
        /*!
         *  \brief Tentative de déplacement à gauche
         *  \param level : Niveau de la partie
         */
        int moveRight(unsigned level);
        /*!
         *  \brief Destructeur Tetrimono
         */
        ~Tetrimono();

};






#endif // TETRIMONO_H
