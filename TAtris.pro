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
    GameWindow.cpp \
    GridFrame.cpp \
    Grid.cpp \
    Tetrimono.cpp \
    Game.cpp

HEADERS  += \
    Tetrimono.h \
    Structures.h \
    Game.h \
    GameWindow.h \
    GridFrame.h \
    Grid.h

FORMS    += \
    GameWindow.ui

OTHER_FILES += \
    ../../../../Downloads/high-quality-space-backgrounds.jpg \
    ../../../../Downloads/galaxy.jpg

RESOURCES += \
    Ressources.qrc
