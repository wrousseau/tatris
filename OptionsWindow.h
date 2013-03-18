#ifndef OPTIONSWINDOW_H
#define OPTIONSWINDOW_H

/*!
 * \file OptionsWindow.h
 * \brief Jeu TAtris basé sur Tétris
 * \author Simon MANCHEL, Woody ROUSSEAU
 * \version 1.0
 */

#include <QMainWindow>
#include <string>

extern bool isMusicOn;
extern bool areSoundsOn;
extern QString currentTheme;

namespace Ui {
class OptionsWindow;
}

class OptionsWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    /*!
     *  \brief Constructeur OptionsWindow
     *
     *  \param parent : Pointeur vers le parent. Par défaut : NULL
     */
    explicit OptionsWindow(QWidget *parent = 0);
    /*!
     *  \brief Destructeur OptionsWindow
     */
    ~OptionsWindow();

signals:
    void goToMenuSignal();

public slots:
    /*!
     *  \brief Permet de se diriger vers le menu
     */
    void goToMenu();
    /*!
     *  \brief Permet d'activer/desactiver les sons
     *
     *  \param par1 : Etat de la Checkbox (coché ou pas coché)
     */
    void toggleSounds(int par1);
    /*!
     *  \brief Permet d'activer/desactiver la musique
     *
     *  \param par1 : Etat de la Checkbox (coché ou pas coché)
     */
    void toggleMusic(int par1);
    /*!
     *  \brief Permet de changer le thème musical
     *
     *  \param action : pointeur vers le choix déroulant apparaissant dans le menu
     */
    void changeTheme(QAction* action);

    
private:
    Ui::OptionsWindow *ui;
};

#endif // OPTIONSWINDOW_H
