#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include "Tetrimono.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit GameWindow(Tetrimono& par1Tetrimono, QWidget *parent = 0);
    ~GameWindow();
    
private slots:
    void on_ExitButton_clicked();



private:
    Ui::GameWindow *ui;
    void sendTetrimonoToGridFrame(Tetrimono& par1Tetrimono);

};

#endif // GAMEWINDOW_H
