include(../memorymap.pri)

TEMPLATE = app
TARGET = memorymap

SOURCES += \
    main.cpp \
    memorymap.cpp \
    memorymapprivate.cpp \

HEADERS += \
    memorymap.h \
    memorymapprivate.h \

FORMS += \
    memorymap.ui
