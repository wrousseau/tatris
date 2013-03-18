#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // On charge les Images
    loadTetrimonosImages();

    // On instancie les objets (grille, jeu)
    grid = new Grid();
    currentGame = new Game(grid);

    // On définit le premier Tetrimono ainsi que le suivant et on instancie
    int first = rand() % 7;
    nextTetrimonoNumber = rand() % 7;
    nextBlock = new Tetrimono(first, grid);

    // Setup de l'interface
    ui->setupUi(this);
    ui->ScoreLCD->setSegmentStyle(QLCDNumber::Filled);
    ui->nextLabel->setPixmap(QPixmap::fromImage(tetrimonoImages[nextTetrimonoNumber]));

    // On envoie les objets à l'interface de la grille (GridFrame)
    sendObjectsToGridFrame(currentGame,grid,nextBlock,nextTetrimonoNumber);

    // Connexions Signaux / Slots
    QObject::connect(currentGame, SIGNAL(updateScore(int)), this->ui->ScoreLCD, SLOT(display(int)));
    QObject::connect(currentGame, SIGNAL(updateLevel(QString)), this, SLOT(updateLevel(QString)));
    QObject::connect(ui->MainGrid, SIGNAL(updateNextBlock(int)), this, SLOT(setNextTetrimonoNumber(int)));
    QObject::connect(ui->MainGrid, SIGNAL(goToMenuSignal()), this, SLOT(goToMenu()));
    QObject::connect(ui->ExitButton, SIGNAL(clicked()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete grid;
    delete currentGame;
    delete nextBlock;
}

void MainWindow::sendObjectsToGridFrame(Game* par1Game, Grid* par2Grid, Tetrimono* par3Tetrimono, int par4)
{
    ui->MainGrid->setObjects(par1Game, par2Grid, par3Tetrimono, par4);
}

void MainWindow::loadTetrimonosImages()
{
    QImage fullImage(":/ressources/ressources/tetrimonos.png");
    int i = 0;
    for (i = 0; i < 7; i ++)
    {
        tetrimonoImages[i] = fullImage.copy(i*110,0,110,110);
    }
}

int MainWindow::getNextTetrimonoNumber()
{
    return nextTetrimonoNumber;
}

void MainWindow::setNextTetrimonoNumber(int par1)
{
    if (par1 >= 0 && par1 < 7)
    {
        nextTetrimonoNumber = par1;
        ui->nextLabel->setPixmap(QPixmap::fromImage(tetrimonoImages[nextTetrimonoNumber]));
    }
}

void MainWindow::updateLevel(QString par1String)
{
    this->ui->LevelLabel->setText(par1String);
    this->ui->MainGrid->setTimer(0.8*this->ui->MainGrid->getTimer());
}

void MainWindow::goToMenu()
{
    this->hide();
    emit goToMenuSignal();
    delete this;
}

