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
            if (currentTetrimono.getValues(i, j) != 0) {
                p.drawRect(currentTetrimono.getX()+25*j,currentTetrimono.getY()+25*i,25,25);
            }
        }
    }
    p.end();

}

void GridFrame::keyPressEvent( QKeyEvent *k )
{
    switch(k->key()){

            case Qt::Key_Left:
                currentTetrimono.moveLeft();
                repaint();

                break;
            case Qt::Key_Right:
                currentTetrimono.moveRight();
                repaint();
                break;
            case Qt::Key_Down:
                currentTetrimono.fall(25);
                repaint();
                break;
            case Qt::Key_Space:
                currentTetrimono.rotate();
                break;
        }
}

void GridFrame::update() {
    currentTetrimono.fall(25);
    repaint();
    if (currentTetrimono.isOnFloor()) {
        //Grid::fillGrid(currentTetrimono);
        currentTetrimono = Tetrimono(0);
    }
    QWidget::update();
}

void GridFrame::setTetrimono(Tetrimono& par1Tetrimono) {
    currentTetrimono = par1Tetrimono;
}
