/*!
 * \file MenuWindow.cpp
 * \brief Jeu TAtris basé sur Tétris
 * \author Simon MANCHEL, Woody ROUSSEAU
 * \version 1.0
 */

#include "MenuWindow.h"
#include "ui_MenuWindow.h"

MenuWindow::MenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);

    // Signaux pour lancer un jeu, accéder aux options et quitter le jeu
    QObject::connect(ui->play_button,SIGNAL(clicked()),this,SLOT(launchGame()));
    QObject::connect(ui->exit_button,SIGNAL(clicked()),this,SLOT(close()));
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::launchGame()
{
       MainWindow *mainWindow = new MainWindow;
       mainWindow->showNormal();
       QObject::connect(mainWindow,SIGNAL(goToMenuSignal()),this,SLOT(showMenu()));
       this->hide();
       this->close();
}

void MenuWindow::showMenu()
{
    this->showNormal();
}
