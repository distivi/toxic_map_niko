#-------------------------------------------------
#
# Project created by QtCreator 2014-04-13T15:31:39
#
#-------------------------------------------------

QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ToxicMapNiko
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    inputparamsdialog.cpp \
    src/ToxicCalc.cpp

HEADERS  += mainwindow.h \
    inputparamsdialog.h \
    src/ToxicCalc.hpp

FORMS    += mainwindow.ui \
    inputparamsdialog.ui

OTHER_FILES += \
    db/my_db.sqlite \
    media/dawn_of_ubuntu.png
