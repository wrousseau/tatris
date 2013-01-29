#include "GameWindow.h"
#include "QPainter.h"
#include "ui_GameWindow.h"

GameWindow::GameWindow(Tetrimono& par1Tetrimono,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    sendTetrimonoToGridFrame(par1Tetrimono);


}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::on_ExitButton_clicked()
{
    QApplication::exit();
}

void GameWindow::sendTetrimonoToGridFrame(Tetrimono& par1Tetrimono) {
    ui->MainGrid->setTetrimono(par1Tetrimono);
}

