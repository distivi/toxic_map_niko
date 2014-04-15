#-------------------------------------------------
#
# Project created by QtCreator 2014-04-15T00:21:48
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ToxicMapGraphics
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    inputparamsdialog.cpp \
    src/ToxicCalc.cpp \
    src/ExQGraphicsScene.cpp

HEADERS  += mainwindow.h \
    inputparamsdialog.h \
    src/ToxicCalc.hpp \
    src/ExQGraphicsScene.h

FORMS    += mainwindow.ui \
    inputparamsdialog.ui
