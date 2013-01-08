#-------------------------------------------------
#
# Project created by QtCreator 2012-12-22T00:11:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TAtris2
TEMPLATE = app


SOURCES += main.cpp\
        basefenetre.cpp

HEADERS  += basefenetre.h \
    Tetrimono.h \
    Structures.h \
    Block.h

FORMS    += basefenetre.ui \
    guimainmenu.ui
