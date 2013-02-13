#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadTetrimonosImages();

    grid = new Grid();
    currentGame = new Game(grid);
    int first = rand() % 7;
    nextTetrimonoNumber = rand() % 7;
    ui->nextLabel->setPixmap(QPixmap::fromImage(tetrimonoImages[nextTetrimonoNumber]));

    Tetrimono* nextBlock = new Tetrimono(first, grid);
    ui->ScoreLCD->setSegmentStyle(QLCDNumber::Filled);
    QObject::connect(currentGame, SIGNAL(updateScore(int)), this->ui->ScoreLCD, SLOT(display(int)));
    QObject::connect(currentGame, SIGNAL(updateLevel(QString)), this, SLOT(updateLevel(QString)));
    QObject::connect(ui->MainGrid, SIGNAL(updateNextBlock(int)), this, SLOT(setNextTetrimonoNumber(int)));


    player = new QMediaPlayer;
    //player->setMedia(QUrl::fromLocalFile(QDir::current().path() +  QString("/salsa.mp3")));
    player->setMedia(QUrl::fromLocalFile("/Users/wrousseau/Downloads/salsa.mp3"));
    player->setVolume(50);
    player->play();

    sendGameToGridFrame(currentGame);
    sendGridToGridFrame(grid);
    sendTetrimonoToGridFrame(nextBlock,nextTetrimonoNumber);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ExitButton_clicked()
{
    QApplication::exit();
}

void MainWindow::sendTetrimonoToGridFrame(Tetrimono* par1Tetrimono, int par1) {
    ui->MainGrid->setTetrimono(par1Tetrimono);
    ui->MainGrid->setNextTetrimonoNumber(par1);
}

void MainWindow::sendGridToGridFrame(Grid* par1Grid) {
    ui->MainGrid->setGrid(par1Grid);
}

void MainWindow::sendGameToGridFrame(Game* par1Game) {
    ui->MainGrid->setGame(par1Game);
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
    if (par1 >= 0 && par1 < 7) {
        nextTetrimonoNumber = par1;
        ui->nextLabel->setPixmap(QPixmap::fromImage(tetrimonoImages[nextTetrimonoNumber]));

    }
}

void MainWindow::updateLevel(QString par1String)
{
    this->ui->LevelLabel->setText(par1String);
    qDebug() << 1000-this->currentGame->getLevel()*100;
    this->ui->MainGrid->setTimer(1000-this->currentGame->getLevel()*100);
}
