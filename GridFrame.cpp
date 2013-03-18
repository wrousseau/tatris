/*!
 * \file GridFrame.cpp
 * \brief Jeu TAtris basé sur Tétris
 * \author Simon MANCHEL, Woody ROUSSEAU
 * \version 1.0
 */

#include "GridFrame.h"
#include "time.h"
#include "unistd.h"

GridFrame::GridFrame(QWidget *parent) :
    QFrame(parent)
{
    this->setFocusPolicy(Qt::StrongFocus);
    isPlaying = true;
    timerForGameOver = 1;
    hasLost = false;


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
        timer->start(1000);
        fallingTimer = new QTimer(this);
        connect(fallingTimer,SIGNAL(timeout()), this, SLOT(updateFalling()));

        gameOverSound = new QMediaPlayer;
        gameOverSound->setMedia(QUrl::fromLocalFile(globalPath + "gameOver.mp3"));
        if (!areSoundsOn)
        {
            gameOverSound->setVolume(0);
        }


        music = new QMediaPlayer;
        music->setMedia(QUrl::fromLocalFile(globalPath + currentTheme + ".mp3"));
        music->setVolume(50);
        music->play();
        if (!isMusicOn)
        {
            music->setVolume(0);
        }


        connect(music,SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), this, SLOT(replayMusic(QMediaPlayer::MediaStatus)));
}

GridFrame::~GridFrame()
{
    #ifdef Q_OS_WIN32
    delete music;
    delete gameOverSound;
    #endif
    delete fallingTimer;
    delete timer;
}


void GridFrame::setObjects(Game *par1Game, Grid *par2Grid, Tetrimono *par3Tetrimono, int par4)
{
    currentGame=par1Game;
    grid=par2Grid;
    currentTetrimono = par3Tetrimono;
    nextTetrimonoNumber = par4;
}

void GridFrame::setBrush(blockColor color, QPainter &p){

    if(color == RED)
    {
        p.setBrush(Qt::red);
    }
    else if(color == GREEN)
    {
        p.setBrush(Qt::green);
    }
    else if(color == BLUE)
    {
        p.setBrush(Qt::blue);
    }
    else if(color == YELLOW)
    {
        p.setBrush(Qt::yellow);
    }
    else if(color == CYAN)
    {
        p.setBrush(QColor(0,255,255));
    }
    else if(color == BROWN)
    {
        p.setBrush(QColor(122, 50, 8));
    }
    else if(color == EMPTY)
    {
        p.setBrush(QColor(0, 0, 0));
    }
    else if(color == PURPLE)
    {
        p.setBrush(QColor(140, 0, 255));
    }
    else if(color == ORANGE)
    {
        p.setBrush(QColor(255, 106, 0));
    }
}

void GridFrame::paintEvent(QPaintEvent*)
{

    QPainter p;
    p.begin(this);

    if (hasLost) {

        for (int i = GRID_HEIGHT-timerForGameOver; i < GRID_HEIGHT; i++) {
            for (int j = 0; j < GRID_WIDTH; j++) {
                setBrush(BROWN, p);
                p.drawRect(j*25, i*25, 25, 25);
            }
        }
        timerForGameOver++;
        if (timerForGameOver == GRID_HEIGHT) {
            pause();
            music->stop();
            gameOverSound->play();qDebug() << "yuouhou";
        }
        return;
    }

    setBrush(currentTetrimono->getColor(), p);
    for (int i = 0; i < 5; i ++) {
        for (int j = 0; j < 5; j++) {
            if (currentTetrimono->getValues(i, j) != 0) {
                p.drawRect(currentTetrimono->getX()+25*j,currentTetrimono->getY()+25*i,25,25);
            }

        }
    }
    for (int i = grid->getHighest(); i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            if (grid->getValues(i, j) != EMPTY) {
                setBrush(grid->getValues(i, j), p);
                p.drawRect(j*25, i*25, 25, 25);
            }
        }
    }
    p.end();
}

void GridFrame::keyPressEvent( QKeyEvent *k )
{
    switch(k->key()){

            case Qt::Key_Left:
                currentTetrimono->moveLeft(currentGame->getLevel());
                repaint();

                break;
            case Qt::Key_Right:
                currentTetrimono->moveRight(currentGame->getLevel());
                repaint();
                break;
            case Qt::Key_Down:
                if (!fallingTimer->isActive()){
                    fallingTimer->start(20);
                }
                break;
            case Qt::Key_P:
                pause();
                break;
            case Qt::Key_Escape:
                music->stop();
                emit goToMenuSignal();
                break;
            case Qt::Key_Space:
                currentTetrimono->rotate();
                repaint();
                break;
    }
}

void GridFrame::keyReleaseEvent(QKeyEvent *k)
{
    switch(k->key()){
            case Qt::Key_Down:
            fallingTimer->stop();
            break;

    }
}

void GridFrame::update() {
    float tmp = (float)15/19;

    currentTetrimono->fall(25);
    repaint();
    if(!hasLost)
        setTimer(1000*tmp/(currentGame->getLevel() + tmp));
    else
        setTimer(75);
    if (currentTetrimono->isOnFloor()) {
        if (currentTetrimono->getUpperBound() <= 0) {
            hasLost = true;
            return;
        }
        currentGame->scoreManage();
        delete currentTetrimono; // on désaloue la mémoire  du tétrimono sur le sol
        currentTetrimono = new Tetrimono(nextTetrimonoNumber, grid);
        int i = rand() % 7;
        nextTetrimonoNumber = i;
        emit updateNextBlock(i);
    }
    QWidget::update();
}

void GridFrame::updateFalling() {
    currentTetrimono->fall(25);
    repaint();
}



void GridFrame::replayMusic(QMediaPlayer::MediaStatus status)
{
   if (status == QMediaPlayer::EndOfMedia) {
       QTimer::singleShot(2000, music, SLOT(play()));
       music->play();
   }
}


void GridFrame::pause() {
    if (isPlaying) {
        timer->stop();
        if (isMusicOn)
            music->setVolume(10);
    }
    else {
        timer->start(1000);
        if (isMusicOn)
            music->setVolume(50);
    }
    update();
    isPlaying = !isPlaying;
}

void GridFrame::setTimer(int par1)
{
    timer->setInterval(par1);
}

void GridFrame::setGameState(bool par1)
{
    hasLost = par1;
}

int GridFrame::getTimer()
{
    return timer->interval();
}

void GridFrame::showPauseMenu()
{
}
