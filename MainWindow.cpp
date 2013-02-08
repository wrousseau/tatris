#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    int i = rand() % 7;
    Grid* grille = new Grid();
    game.setGrid(grille);
    Tetrimono* nextBlock = new Tetrimono(i, grille);
    ui->setupUi(this);

    Phonon::MediaObject *music =
        Phonon::createPlayer(Phonon::MusicCategory,
                             Phonon::MediaSource("/Users/wrousseau/Downloads/salsa.mp3"));
    music->play();

    sendGridToGridFrame(grille);
    sendTetrimonoToGridFrame(nextBlock);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ExitButton_clicked()
{
    QApplication::exit();
}

void MainWindow::sendTetrimonoToGridFrame(Tetrimono* par1Tetrimono) {
    ui->MainGrid->setTetrimono(par1Tetrimono);
}

void MainWindow::sendGridToGridFrame(Grid* par1Grid) {
    ui->MainGrid->setGrid(par1Grid);
}
