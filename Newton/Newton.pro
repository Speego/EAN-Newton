#-------------------------------------------------
#
# Project created by QtCreator 2016-05-29T09:40:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Newton
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    newtonrootsnormal.cpp \
    newtonrootsinterval.cpp

HEADERS  += mainwindow.h \
    Interval.h \
    newtonrootsnormal.h \
    newtonrootsinterval.h

FORMS    += mainwindow.ui

LIBS += -lboost_system\
        -lmpfr -lgmp
