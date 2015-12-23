
INCLUDEPATH += $$PWD/include/
LIBS += -L$$PWD/lib/ -lmemorymap 
LIBS += -L$$PWD/src/QHexEdit/ -lQHexEdit

win32-msvc* {
	PRE_TARGETDEPS += $$PWD/src/QHexEdit/QHexEdit.lib
	PRE_TARGETDEPS += $$PWD/lib/memorymap.lib
} else {
	PRE_TARGETDEPS += $$PWD/src/QHexEdit/libQHexEdit.a
	PRE_TARGETDEPS += $$PWD/lib/libmemorymap.a
}

include($$PWD/../projectview/include.pri)
include($$PWD/../propellermanager/include.pri)
