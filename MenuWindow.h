#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "MainWindow.h"
#include "OptionsWindow.h"
#include <QCheckBox>

extern bool isMusicOn;
extern bool areSoundsOn;


namespace Ui {
class MenuWindow;
}

class MenuWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MenuWindow(QWidget *parent = 0);
    ~MenuWindow();

public slots:
    void launchGame();
    void showMenu();
    void launchOptions();




    
private:
    Ui::MenuWindow *ui;
};

#endif // MENUWINDOW_H
