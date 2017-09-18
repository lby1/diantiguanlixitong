#-------------------------------------------------
#
# Project created by QtCreator 2017-08-24T10:36:00
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = diantiguanlixitong
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    qreplytimeout.cpp \
    mytitlebar.cpp \
    basewindow.cpp \
    mainwindow1.cpp \
    globalvar.cpp \
    deviceinfo.cpp \
    itemdelegateforcol.cpp \
    remark.cpp

HEADERS  += mainwindow.h \
    login.h \
    qreplytimeout.h \
    mytitlebar.h \
    basewindow.h \
    mainwindow1.h \
    globalvar.h \
    deviceinfo.h \
    itemdelegateforcol.h \
    remark.h

FORMS    += mainwindow.ui \
    login.ui \
    basewin.ui \
    mainwindow1.ui \
    deviceinfo.ui \
    remark.ui

RESOURCES += \
    source.qrc

DISTFILES +=
