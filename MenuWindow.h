#ifndef MENUWINDOW_H
#define MENUWINDOW_H

/*!
 * \file MenuWindow.h
 * \brief Jeu TAtris basé sur Tétris
 * \author Simon MANCHEL, Woody ROUSSEAU
 * \version 1.0
 */

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "MainWindow.h"
#include "OptionsWindow.h"
#include <QCheckBox>

extern bool isMusicOn;
extern bool areSoundsOn;


namespace Ui {
class MenuWindow;
}

class MenuWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    /*!
     *  \brief Constructeur MenuWindow
     *
     *  \param parent : Pointeur vers le parent. Par défaut : NULL
     */
    explicit MenuWindow(QWidget *parent = 0);
    /*!
     *  \brief Destructeur MenuWindow
     */
    ~MenuWindow();

public slots:
    /*!
     *  \brief Lance la partie
     */
    void launchGame();
    /*!
     *  \brief Affiche la fenêtre menu
     */
    void showMenu();
    /*!
     *  \brief Charge les options
     */
    void launchOptions();




    
private:
    Ui::MenuWindow *ui;
};

#endif // MENUWINDOW_H
