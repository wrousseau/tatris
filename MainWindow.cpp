#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    grid = new Grid();
    currentGame = new Game(grid);
    int i = rand() % 7;
    qDebug() << grid->isLineFull(10) ;
    Tetrimono* nextBlock = new Tetrimono(i, grid);
    ui->ScoreLCD->setSegmentStyle(QLCDNumber::Filled);
    QObject::connect(currentGame, SIGNAL(updateScore(int)), this->ui->ScoreLCD, SLOT(display(int)));
    QObject::connect(currentGame, SIGNAL(updateLevel(QString)), this->ui->LevelLabel, SLOT(setText(QString)));


    player = new QMediaPlayer;
    qDebug() << QDir::current().path() +  QString("salsa.mp3");
    player->setMedia(QUrl::fromLocalFile(QDir::current().path() +  QString("/salsa.mp3")));
    player->setVolume(50);
    //player->play();

    sendGameToGridFrame(currentGame);
    sendGridToGridFrame(grid);
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

void MainWindow::sendGameToGridFrame(Game* par1Game) {
    ui->MainGrid->setGame(par1Game);
}
