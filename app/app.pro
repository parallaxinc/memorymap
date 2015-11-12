QT += gui widgets

LIBS += -L../lib/ -lmemorymap -lQHexEdit
INCLUDEPATH += ../include/

win32-msvc* {
	PRE_TARGETDEPS += ../lib/QHexEdit.lib \
                      ../lib/memorymap.lib 
} else {
	PRE_TARGETDEPS += ../lib/libQHexEdit.a \
                      ../lib/libmemorymap.a
}

TEMPLATE = app
TARGET = memorymap
DESTDIR = ../bin/

SOURCES += main.cpp
