#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "Game.h"
#include "GridFrame.h"


class Tetrimono;
class Grid;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void sendObjectsToGridFrame(Game* par1Game, Grid* par2Grid, Tetrimono* par3Tetrimono, int par4);
    void loadTetrimonosImages();
    int getNextTetrimonoNumber();

public slots:
    void setNextTetrimonoNumber(int par1);
    void updateLevel(QString par1String);
    void goToMenu();

signals:
    void goToMenuSignal();
    
private:
    Ui::MainWindow *ui;
    Game* currentGame;
    Grid* grid;
    QImage tetrimonoImages[7];
    int nextTetrimonoNumber;
};

#endif // MAINWINDOW_H
