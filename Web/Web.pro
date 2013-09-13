#-------------------------------------------------
#
# Project created by QtCreator 2013-09-12T22:58:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Web
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    computer.cpp \
    operatingsystem.cpp \
    virus.cpp \
    network.cpp \
    localnetwork.cpp \
    worldwideweb.cpp \
    linuxos.cpp \
    windowsos.cpp \
    linuxvirus.cpp \
    windowsvirus.cpp

HEADERS  += mainwindow.h \
    computer.h \
    operatingsystem.h \
    virus.h \
    network.h \
    localnetwork.h \
    worldwideweb.h \
    linuxos.h \
    windowsos.h \
    linuxvirus.h \
    windowsvirus.h

FORMS    += mainwindow.ui
