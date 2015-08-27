!greaterThan(QT_MAJOR_VERSION, 4): {
    error("memorymap requires Qt5.2 or greater")
}
!greaterThan(QT_MINOR_VERSION, 1): {
    error("memorymap requires Qt5.2 or greater")
}

INCLUDEPATH += . ..

LIBS += -L../QHexEdit -lQHexEdit

win32-msvc* {
	PRE_TARGETDEPS += ../QHexEdit/QHexEdit.lib
} else {
	PRE_TARGETDEPS += ../QHexEdit/libQHexEdit.a
}

QT += gui widgets
CONFIG -= debug_and_release
