include(../include.pri)

QT += gui widgets

TEMPLATE = app
TARGET = memorymap
DESTDIR = ../bin/

SOURCES += main.cpp

isEmpty(PREFIX) {
    PREFIX = /usr/local
}

target.path = $$PREFIX/bin
INSTALLS += target
