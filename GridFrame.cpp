#include "GridFrame.h"
#include "QDebug"

GridFrame::GridFrame(QWidget *parent) :
    QFrame(parent)
{
    this->setFocusPolicy(Qt::StrongFocus);


    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
}

void GridFrame::paintEvent(QPaintEvent*)
{

    QPainter p;
    p.begin(this);
    p.setBrush(Qt::red);

    for (int i = 0; i < 5; i ++) {
        for (int j = 0; j < 5; j++) {
            if (currentTetrimono->getValues(i, j) != 0) {
                p.drawRect(currentTetrimono->getX()+25*j,currentTetrimono->getY()+25*i,25,25);
            }

        }
    }
    for (int i = grid->getHighest(); i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            if (grid->getValues(i, j) != 0) {
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
                currentTetrimono->moveLeft();
                repaint();

                break;
            case Qt::Key_Right:
                currentTetrimono->moveRight();
                repaint();
                break;
            case Qt::Key_Down:
                currentTetrimono->fall(25);
                repaint();
                break;
            case Qt::Key_Space:
                currentTetrimono->rotate();
                repaint();
                break;
        }
}

void GridFrame::update() {
    currentTetrimono->fall(25);
    qDebug() << "glaouch";
    repaint();
    if (currentTetrimono->isOnFloor()) {
        qDebug() << "theere";
        int i = rand() % 3;
        delete currentTetrimono; // on désaloue la mémoire  du tétrimono sur le sol
        currentTetrimono = new Tetrimono(i, grid);// on alloue la mémoire du nouveau en profitant du constructeur
        //Tetrimono nextBlock(i, grid);
        //setTetrimono(&nextBlock);
        //qDebug() << nextBlock.isOnFloor();
    }
    QWidget::update();
}

void GridFrame::setTetrimono(Tetrimono* par1Tetrimono) {
    currentTetrimono = par1Tetrimono;
}

void GridFrame::setGrid(Grid* par1Grid) {
    grid = par1Grid;
}
