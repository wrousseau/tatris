#include "OptionsWindow.h"
#include "QMediaPlayer.h"
#include "ui_OptionsWindow.h"
#include <QMenuBar>
#include <qDebug>

OptionsWindow::OptionsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OptionsWindow)
{
    ui->setupUi(this);
    ui->musicbox->setChecked(isMusicOn);
    ui->soundsbox->setChecked(areSoundsOn);
    QMenuBar *menuBar = new QMenuBar;
    QMenu *musicChoices = menuBar->addMenu("&Musique");
    musicChoices->addAction("salsa");
    musicChoices->addAction("piano");
    musicChoices->addAction("groove");

    ui->changeMusic->setMenu(musicChoices);

    connect(musicChoices, SIGNAL(triggered(QAction*)), this, SLOT(changeTheme(QAction*)));

    QObject::connect(ui->menu_button,SIGNAL(clicked()),this,SLOT(goToMenu()));
    QObject::connect(ui->musicbox,SIGNAL(stateChanged(int)),this,SLOT(toggleMusic(int)));
    QObject::connect(ui->soundsbox,SIGNAL(stateChanged(int)),this,SLOT(toggleSounds(int)));

}

OptionsWindow::~OptionsWindow()
{
    delete ui;
}

void OptionsWindow::goToMenu()
{
    this->hide();
    emit goToMenuSignal();
    delete this;
}

void OptionsWindow::toggleMusic(int par1)
{
    isMusicOn = !isMusicOn;
}

void OptionsWindow::toggleSounds(int par1)
{
    areSoundsOn = !areSoundsOn;
}

void OptionsWindow::changeTheme(QAction* action)
{
    currentTheme = action->text();
}

