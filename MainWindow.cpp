#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    int i = rand() % 4;
    Grid* grille = new Grid();
    game.setGrid(grille);
    Tetrimono* nextBlock = new Tetrimono(i, grille);
    ui->setupUi(this);

    QMediaPlayer* player = new QMediaPlayer;
     QFile::copy (":/salsa.mp3", "salsa.mp3");
    QUrl url("salsa.mp3");

    QMediaPlaylist * playlist = new QMediaPlaylist();
    playlist->addMedia(url);
    playlist->setPlaybackMode( QMediaPlaylist::Loop );
    player->setPlaylist( playlist );
    playlist->setCurrentIndex(0);
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
