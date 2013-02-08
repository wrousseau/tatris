#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsView>
#include <QtMultimedia>


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
    
private:
    Ui::MainWindow *ui;
    void sendTetrimonoToGridFrame(Tetrimono* par1Tetrimono);
    void sendGridToGridFrame(Grid* par1Grid);


private slots:
    void on_ExitButton_clicked();

};

#endif // MAINWINDOW_H
