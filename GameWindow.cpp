#include "GameWindow.h"
#include "QPainter.h"
#include "Tetrimono.h"
#include "ui_GameWindow.h"

GameWindow::GameWindow(Tetrimono& par1Tetrimono, Grid* par2Grille, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    sendGridToGridFrame(par2Grille);
    sendTetrimonoToGridFrame(&par1Tetrimono);


}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::on_ExitButton_clicked()
{
    QApplication::exit();
}

void GameWindow::sendTetrimonoToGridFrame(Tetrimono* par1Tetrimono) {
    ui->MainGrid->setTetrimono(par1Tetrimono);
}

void GameWindow::sendGridToGridFrame(Grid* par1Grid) {
    ui->MainGrid->setGrid(par1Grid);
}

