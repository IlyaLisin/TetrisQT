#-------------------------------------------------
#
# Project created by QtCreator 2015-12-22T20:57:23
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TetrisQT
TEMPLATE = app


SOURCES += main.cpp \
    tetrisview.cpp \
    game.cpp \
    board.cpp \
    figure.cpp \
    controller.cpp \
    figureview.cpp

HEADERS  += \
    tetrisview.h \
    game.h \
    board.h \
    figure.h \
    controller.h \
    figureview.h

FORMS    += widget.ui
