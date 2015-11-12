include(../src.pri)

TEMPLATE = lib
TARGET = memorymap

LIBS += -L../../lib/ -lQHexEdit

win32-msvc* {
	PRE_TARGETDEPS += ../../lib/QHexEdit.lib
} else {
	PRE_TARGETDEPS += ../../lib/libQHexEdit.a
}

SOURCES += \
    memorymap.cpp \
    memorymapprivate.cpp \

HEADERS += \
    memorymap.h \
    memorymapprivate.h \

FORMS += \
    memorymap.ui
