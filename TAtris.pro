#-------------------------------------------------
#
# Project created by QtCreator 2012-12-22T00:11:57
#
#-------------------------------------------------

QT       += core gui

TARGET = tatris

TEMPLATE = app

SOURCES += main.cpp \
    GridFrame.cpp \
    Grid.cpp \
    Tetrimono.cpp \
    Game.cpp \
    MainWindow.cpp \
    MenuWindow.cpp

HEADERS  += \
    Tetrimono.h \
    Structures.h \
    Game.h \
    GridFrame.h \
    Grid.h \
    MainWindow.h \
    MenuWindow.h

FORMS    += \
    MainWindow.ui \
    MenuWindow.ui

RESOURCES += \
    Ressources.qrc

QT += multimedia widgets

CONFIG -= console
