#include "MenuWindow.h"
#include "ui_MenuWindow.h"

MenuWindow::MenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->play_button,SIGNAL(clicked()),this,SLOT(launchGame()));
    QObject::connect(ui->exit_button,SIGNAL(clicked()),this,SLOT(close()));

}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::launchGame()
{
       MainWindow *mainWindow = new MainWindow;
       mainWindow->showNormal();
       QObject::connect(mainWindow,SIGNAL(goToMenuSignal()),this,SLOT(showMenu()));
       this->hide();
}

void MenuWindow::showMenu()
{
    this->showNormal();
}
