#-------------------------------------------------
#
# Project created by QtCreator 2016-11-23T13:01:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FileThread
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    filethread.cpp \
    wordscounter.cpp

HEADERS  += mainwindow.h \
    filethread.h \
    wordscounter.h

FORMS    += mainwindow.ui
