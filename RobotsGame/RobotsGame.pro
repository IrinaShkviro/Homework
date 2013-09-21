#-------------------------------------------------
#
# Project created by QtCreator 2013-09-21T17:54:31
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = RobotsGame
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    workwithfile.cpp \
    graph.cpp \
    graphnode.cpp

HEADERS += \
    workwithfile.h \
    graph.h \
    graphnode.h \
    graphnodetest.h \
    workwithfiletest.h \
    graphtest.h

RESOURCES += \
    dataFile.qrc
