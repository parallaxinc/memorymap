!greaterThan(QT_MAJOR_VERSION, 4): {
    error("memorymap requires Qt5.2 or greater")
}
!greaterThan(QT_MINOR_VERSION, 1): {
    error("memorymap requires Qt5.2 or greater")
}

INCLUDEPATH += . ..

LIBS += -lQHexEdit -L$$PWD/QHexEdit/

QT += gui widgets
