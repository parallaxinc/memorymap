QT += gui widgets

LIBS += -L../memorymap/  -lmemorymap
LIBS += -L../QHexEdit -lQHexEdit

INCLUDEPATH += . .. ../memorymap/

TEMPLATE = app
TARGET = memorymap

SOURCES += main.cpp
