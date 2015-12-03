INCLUDEPATH += $$PWD/include/
LIBS += -L$$PWD/lib/ -lmemorymap -lQHexEdit

win32-msvc* {
	PRE_TARGETDEPS += $$PWD/lib/QHexEdit.lib
	PRE_TARGETDEPS += $$PWD/lib/memorymap.lib
} else {
	PRE_TARGETDEPS += $$PWD/lib/libQHexEdit.a
	PRE_TARGETDEPS += $$PWD/lib/libmemorymap.a
}
