include(../memorymap.pri)

TEMPLATE = lib
TARGET = memorymap
CONFIG += staticlib

SOURCES += \
    memorymap.cpp \
    memorymapprivate.cpp \

HEADERS += \
    memorymap.h \
    memorymapprivate.h \

FORMS += \
    memorymap.ui
