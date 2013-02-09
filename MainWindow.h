#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "Game.h"


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
    void sendTetrimonoToGridFrame(Tetrimono* par1Tetrimono);
    void sendGridToGridFrame(Grid* par1Grid);
    void sendGameToGridFrame(Game* par1Game);
    
private:
    Ui::MainWindow *ui;
    Game* currentGame;
    Grid* grid;
    QMediaPlayer* player;

private slots:
    void on_ExitButton_clicked();

};

#endif // MAINWINDOW_H
