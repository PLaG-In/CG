#-------------------------------------------------
#
# Project created by QtCreator 2015-09-11T08:48:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        table.cpp \
    team.cpp \
    mydelegate.cpp \
    input.cpp

HEADERS  += table.h \
    team.h \
    mydelegate.h \
    input.h

FORMS    += table.ui \
    input.ui
