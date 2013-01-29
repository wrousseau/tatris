#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();
    
private slots:
    void on_ExitButton_clicked();


private:
    Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_H
