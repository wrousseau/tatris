#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
class Tetrimono;
class Grid;

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit GameWindow(Tetrimono& par1Tetrimono, Grid* par2Grid, QWidget *parent = 0);
    ~GameWindow();
    
private slots:
    void on_ExitButton_clicked();



private:
    Ui::GameWindow *ui;
    void sendTetrimonoToGridFrame(Tetrimono* par1Tetrimono);
    void sendGridToGridFrame(Grid* par1Grid);

};

#endif // GAMEWINDOW_H
