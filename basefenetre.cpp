#include "basefenetre.h"

BaseFenetre::BaseFenetre()
{
    setMaximumSize(QSize(800,600));
    QWidget *zoneCentrale = new QWidget;
    zoneCentrale->setFixedSize(QSize(800,600));
    zoneCentrale->setStyleSheet("background-color: black;");
    setCentralWidget(zoneCentrale);

}
