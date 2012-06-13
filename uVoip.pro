#-------------------------------------------------
#
# Project created by QtCreator 2012-06-09T18:09:29
#
#-------------------------------------------------

QT       += core gui multimedia network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = uVoip
TEMPLATE = app


SOURCES += main.cpp \
    uvoip.cpp \
    visualaudiolevel.cpp \
    audiostream.cpp \
    audioplayback.cpp \
    client.cpp \
    server.cpp

HEADERS  += \
    uvoip.h \
    visualaudiolevel.h \
    audiostream.h \
    audioplayback.h \
    client.h \
    server.h

FORMS +=
