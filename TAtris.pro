#-------------------------------------------------
#
# Project created by QtCreator 2012-12-22T00:11:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TAtris2
TEMPLATE = app

CONFIG += console


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
