#-------------------------------------------------
#
# Project created by QtCreator 2016-02-05T11:38:43
#
#-------------------------------------------------

QT       += core gui network

CONFIG +=  c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PentaxRemote
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    httpinterface.cpp

HEADERS  += mainwindow.h \
    httpinterface.h

FORMS    += mainwindow.ui
