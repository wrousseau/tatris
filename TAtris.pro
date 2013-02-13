#-------------------------------------------------
#
# Project created by QtCreator 2012-12-22T00:11:57
#
#-------------------------------------------------

QT       += core gui


TARGET = TAtris2

TEMPLATE = app



SOURCES += main.cpp \
    GridFrame.cpp \
    Grid.cpp \
    Tetrimono.cpp \
    Game.cpp \
    MainWindow.cpp

HEADERS  += \
    Tetrimono.h \
    Structures.h \
    Game.h \
    GridFrame.h \
    Grid.h \
    MainWindow.h

FORMS    += \
    MainWindow.ui


RESOURCES += \
    Ressources.qrc

myFiles.sources = ressources*.mp3
DEPLOYMENT += myFiles



QT += multimedia widgets



