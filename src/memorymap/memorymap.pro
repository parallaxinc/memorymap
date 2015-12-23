include(../QHexEdit/include.pri)
include(../../../projectview/include.pri)
include(../../../propellermanager/include.pri)

QT += gui widgets

CONFIG -= debug_and_release app_bundle
CONFIG += staticlib

TEMPLATE = lib
TARGET = memorymap
DESTDIR = ../../lib/

SOURCES += \
    memorymap.cpp \
    memorymapprivate.cpp \

HEADERS += \
    memorymap.h \
    memorymapprivate.h \
    memorybar.h \

FORMS += \
    memorymap.ui
