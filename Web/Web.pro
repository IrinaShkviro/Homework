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
    linuxos.cpp \
    windowsos.cpp \
    program.cpp \
    linuxvirus.cpp \
    windowsvirus.cpp \
    localnetwork.cpp \
    saver.cpp \
    virus.cpp

HEADERS  += mainwindow.h \
    computer.h \
    operatingsystem.h \
    virus.h \
    linuxos.h \
    windowsos.h \
    program.h \
    linuxvirus.h \
    windowsvirus.h \
    localnetwork.h \
    saver.h

FORMS    += mainwindow.ui
