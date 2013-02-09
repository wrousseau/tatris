#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    int i = rand() % 7;
    Grid* grille = new Grid();
    game.setGrid(grille);
    Tetrimono* nextBlock = new Tetrimono(i, grille);
    ui->setupUi(this);

    player = new QMediaPlayer;
    qDebug() << QDir::current().path() +  QString("salsa.mp3");
    player->setMedia(QUrl::fromLocalFile(QDir::current().path() +  QString("/salsa.mp3")));
    player->setVolume(50);
    player->play();

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
