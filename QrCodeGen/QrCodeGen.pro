#-------------------------------------------------
#
# Project created by QtCreator 2015-01-23T23:15:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QrCodeGen
TEMPLATE = app


SOURCES += main.cpp\
        qrmainwindow.cpp

HEADERS  += qrmainwindow.h

QT += network
QT += printsupport


FORMS    += qrmainwindow.ui
