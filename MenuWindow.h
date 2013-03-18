#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QObject>
#include "MainWindow.h"


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

    
private:
    Ui::MenuWindow *ui;
};

#endif // MENUWINDOW_H
